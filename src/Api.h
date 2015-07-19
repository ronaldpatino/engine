//
// Created by ronald on 12/07/15.
//

#ifndef ENGINE_API_H
#define ENGINE_API_H

#include <lua.hpp>
int my_multiply(int a, int b);
void RegisterEntity(lua_State * l);
int ReturnArray(lua_State* l);

#endif //ENGINE_API_H
