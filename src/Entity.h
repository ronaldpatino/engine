//
// Created by ronald on 12/07/15.
//

#ifndef ENGINE_OBJECTO_H
#define ENGINE_OBJECTO_H

#include <allegro.h>
#include <string>
#include <vector>

#define DIR_UP			0
#define DIR_LEFT		1
#define DIR_RIGHT		2
#define DIR_DOWN		3

static int const FRAME_DELAY = 10;


class Entity {

public:
    Entity(BITMAP *bitmap, int x, int y) : bitmap(bitmap), x(x), y(y) { }

    Entity(const char *imagen, int x, int y, const char *script, const char *name, int frames, int width, int height);

    BITMAP * getFrame();

    void walk(int dir);

    char *imagen;
    BITMAP *bitmap;
    std::vector<BITMAP *>anim;
    int     x,
            y,
            mx,
            my,
            dir,
            width,
            height,
            curframe,
            frames,
            frame_delay;

    char script[256];
    char name[256];
    int     health,
            max_health;

    ~Entity() { }

};

#endif //ENGINE_OBJECTO_H
