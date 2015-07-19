//
// Created by ronald on 12/07/15.
//

#ifndef ENGINE_ENGINE_H
#define ENGINE_ENGINE_H

#include <allegro.h>
#include <list>
#include "Entity.h"

BITMAP *buffer;
bool game_end = false;
std::list<Entity *> objects_list;
std::list<Entity *>::iterator itr;
#endif //ENGINE_ENGINE_H
