#include <iostream>
#include "engine.h"
#include "Api.h"

using namespace std;

void init_engine();
void shutdown_engine();
void handle_input();
void update_screen();
void draw_screen();
void init_objects();

int main() {




    init_engine();
    lua_State * l = luaL_newstate();
    luaL_openlibs(l);
    RegisterEntity(l);
    int erred = luaL_dofile(l, "/home/ronald/ClionProjects/engine/scripts/test.lua");
    if(erred) {
        std::cout << "Lua error: " << luaL_checkstring(l, -1) << std::endl;
    }


    init_objects();

    do {

        handle_input();
        draw_screen();

    } while (!game_end);

    shutdown_engine();
    lua_close(l);
    return 0;
}


void init_engine(){

    allegro_init();
    install_keyboard();
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
}

void handle_input(){
    if(key[KEY_ESC]) { game_end = true; }
}

void draw_screen(){

    for(itr = objects_list.begin(); itr != objects_list.end(); itr++){
        draw_sprite(buffer, (*itr)->bitmap, (*itr)->x, (*itr)->y);
    }


    update_screen();
}

void update_screen(){
    blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
}

void init_objects(){

    Entity *npc = new Entity(load_bitmap("/home/ronald/ClionProjects/luallegro/000.bmp", NULL),0,0);
    Entity *npc2 = new Entity(load_bitmap("/home/ronald/ClionProjects/luallegro/000.bmp", NULL),200,50);

    objects_list.push_front(npc);
    objects_list.push_front(npc2);

}