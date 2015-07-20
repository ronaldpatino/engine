//
// Created by ronald on 12/07/15.
//

#include <iostream>
#include "Entity.h"




Entity::Entity(char *imagen, int x, int y, char *script, char *name) {

    this->bitmap = load_bitmap(imagen, NULL);
    this->x = x;
    this->y = y;
    strcpy(this->script, script);
    strcpy(this->name, name);
}

