//
// Created by ronald on 12/07/15.
//
#include "Entity.h"

Entity::Entity(const char *imagen, int x, int y, const char *script, const char *name, int frames, int width, int height) {

    this->bitmap = load_bitmap(imagen, NULL);
    this->x = x;
    this->y = y;
    this->height = height;
    this->width = width;
    this->curframe = 0;
    strcpy(this->script, script);
    strcpy(this->name, name);
    this->frames = frames;
    this->frame_delay = FRAME_DELAY;

    for (int f=0; f<= this->frames; f++){
        this->anim.push_back(create_sub_bitmap(this->bitmap, f * this->width, 0, this->width, this->height));
    }

}

BITMAP * Entity::getFrame(){

    if(this->frame_delay <= 0){
        this->curframe = (this->curframe +1 ) % this->frames;
        this->frame_delay = FRAME_DELAY;
    }
    else{
        this->frame_delay--;
    }

    return this->anim[this->curframe];
}

void Entity::walk(int dir){

    int next_x = x, next_y = y;

    switch (dir) {
        case DIR_UP:    next_y -= 2; break;
        case DIR_DOWN:  next_y += 2; break;
        case DIR_LEFT:  next_x -= 2; break;
        case DIR_RIGHT: next_x += 2; break;
    }

    this->x = next_x;
    this->y = next_y;
}
