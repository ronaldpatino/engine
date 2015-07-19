cmake_minimum_required(VERSION 3.2)
project(engine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp)
add_executable(engine ${SOURCE_FILES} src/Entity.cpp src/Entity.h src/engine.h src/Api.cpp src/Api.h)

set(LUA_INCLUDE_DIR "/usr/local/include/lua5.2" CACHE FILEPATH "/usr/local/include/lua5.2")

if(${LUA_INCLUDE_DIR})
  if(NOT EXISTS ${LUA_INCLUDE_DIR}/lua.h)
    message(SEND_ERROR "Can't find lua.h in ${LUA_INCLUDE_DIR}")
  endif()
endif()

INCLUDE_DIRECTORIES( /usr/local/include/ ${LUA_INCLUDE_DIR})
TARGET_LINK_LIBRARIES(engine lua alleg)
LINK_DIRECTORIES( /usr/local/lib)