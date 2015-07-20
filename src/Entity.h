//
// Created by ronald on 12/07/15.
//

#ifndef ENGINE_OBJECTO_H
#define ENGINE_OBJECTO_H

#include <allegro.h>
#include <string>

class Entity {

public:
    Entity(BITMAP *bitmap, int x, int y) : bitmap(bitmap), x(x), y(y) { }


    Entity(char *imagen, int x, int y, char *script, char *name) ;

    char *imagen;
    BITMAP *bitmap;
    int     x,
            y,
            mx,
            my,
            dir;

    char script[256];
    char name[256];
    int     health,
            max_health;


    ~Entity() { }

};

#endif //ENGINE_OBJECTO_H
