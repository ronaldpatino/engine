//
// Created by ronald on 12/07/15.
//
#include "Api.h"
#include "Entity.h"


int my_multiply(int a, int b) {
    return (a*b);
}

int crete_entity(lua_State *l){

    const char *b = luaL_checkstring(l,1);
    int x = luaL_checkinteger(l, 2);
    int y = luaL_checkinteger(l, 3);

    Entity **pEntity = (Entity**)lua_newuserdata( l, sizeof(Entity*));
    *pEntity = new Entity(load_bitmap(b, NULL),x,y);
    luaL_getmetatable(l, "luaL_Entity");
    lua_setmetatable(l, -2);
    return 1;
}

void RegisterEntity(lua_State * l) {
    luaL_Reg sFooRegs[] =
            {
                    { "new", crete_entity },
                    { NULL, NULL }
            };

    // Create a luaL metatable. This metatable is not
    // exposed to Lua. The "luaL_Foo" label is used by luaL
    // internally to identity things.
    luaL_newmetatable(l, "luaL_Foo");

    // Register the C functions _into_ the metatable we just created.
    luaL_setfuncs (l, sFooRegs, 0);

    // The Lua stack at this point looks like this:
    //
    //     1| metatable "luaL_Foo"   |-1
    lua_pushvalue(l, -1);

    // The Lua stack at this point looks like this:
    //
    //     2| metatable "luaL_Foo"   |-1
    //     1| metatable "luaL_Foo"   |-2

    // Set the "__index" field of the metatable to point to itself
    // This pops the stack
    lua_setfield(l, -1, "__index");

    // The Lua stack at this point looks like this:
    //
    //     1| metatable "luaL_Foo"   |-1

    // The luaL_Foo metatable now has the following fields
    //     - __gc
    //     - __index
    //     - add
    //     - new

    // Now we use setglobal to officially expose the luaL_Foo metatable
    // to Lua. And we use the name "Foo".
    //
    // This allows Lua scripts to _override_ the metatable of Foo.
    // For high security code this may not be called for but
    // we'll do this to get greater flexibility.
    lua_setglobal(l, "Entity");
}
