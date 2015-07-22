#include <iostream>
#include "engine.h"
#include "Api.h"

void ticker(){
    cout << ticks << endl;
    ticks++;
}
END_OF_FUNCTION(ticker)

int main() {

    init_engine();
    init_script();
    init_objects();

    while (!game_end) {

        handle_input();
        draw_screen();

    }

    shutdown_engine();

    return 0;
}
END_OF_MAIN() // This must be called right after the closing bracket of your MAIN function.




void init_engine(){

    allegro_init();
    install_keyboard();
    install_timer();


    LOCK_VARIABLE(ticks);
    LOCK_FUNCTION(ticker);
    install_int_ex(ticker, BPS_TO_TIMER(updates_per_second));

    set_color_depth(16);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);


    if (!(buffer = create_bitmap(SCREEN_W, SCREEN_H))) exit(1);
    clear_bitmap(buffer);
    clear(screen);


}

void shutdown_engine(){
    destroy_bitmap(buffer);
    for(itr = objects_list.begin(); itr != objects_list.end(); itr++){
        delete *itr;
    }
    objects_list.clear();
    remove_int(ticker);
}

void handle_input(){
    if(key[KEY_ESC]) { game_end = true; }
}

void draw_screen(){

    clear(buffer);
    for(itr = objects_list.begin(); itr != objects_list.end(); itr++){
        draw_sprite(buffer, (*itr)->getFrame(), (*itr)->x, (*itr)->y);
    }
    update_screen();
}

void update_screen(){
    blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
}

void init_objects(){

    for (int i=0; i<=int(state["Entities"]["size"]); i++ ){

        string nombre = state["Entities"][i]["nombre"];
        string script = state["Entities"][i]["script"];
        state.Load(script);
        state["init"]();
        string bmp = state["Entity"]["img"];
        int x = state["Entity"]["x"];
        int y = state["Entity"]["y"];
        int frames = state["Entity"]["frames"];
        int width = state["Entity"]["width"];
        int height = state["Entity"]["height"];

        //objects_list.push_front(new Entity(load_bitmap(bmp.c_str(), NULL), x, y));

        objects_list.push_front(new Entity(bmp.c_str(), x, y, script.c_str(), nombre.c_str(),frames, width,height));

    }

}

void init_script(){
    state["lmultiply"] = std::function<int(int, int)>(my_multiply);
    state["lsay"] = std::function<int(std::string)>(say);
    state.Load("/home/ronald/ClionProjects/engine/scripts/entities.lua");
    state["init"]();
}