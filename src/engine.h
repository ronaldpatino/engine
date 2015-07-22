//
// Created by ronald on 12/07/15.
//

#ifndef ENGINE_ENGINE_H
#define ENGINE_ENGINE_H

#include <allegro.h>
#include <semaphore.h>
#include <list>
#include "Entity.h"
#include "selene.h"

using namespace sel;
using namespace std;

void init_engine();
void shutdown_engine();
void handle_input();
void update_screen();
void draw_screen();
void init_objects();
void init_script();

const int updates_per_second = 60;
BITMAP *buffer;
bool game_end = false;
std::list<Entity *> objects_list;
std::list<Entity *>::iterator itr;
State state{true};
volatile int ticks = 0;

#endif //ENGINE_ENGINE_H
