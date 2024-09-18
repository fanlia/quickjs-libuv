cmake_minimum_required(VERSION 3.30)
project(quickjs-libuv LANGUAGES C)

set(BUILD_SHARED_LIBS ON)
add_subdirectory(./deps/quickjs)
add_subdirectory(./deps/libuv)

add_library(qu SHARED ./src/qu.c)
target_link_libraries(qu qjs uv)
