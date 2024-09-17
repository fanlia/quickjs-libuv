cmake_minimum_required(VERSION 3.30)
project(quickjs-libuv LANGUAGES C)

add_subdirectory(./deps/quickjs)
add_subdirectory(./deps/libuv)

link_libraries(qjs uv)
aux_source_directory(./src SRC)
add_executable(test ${SRC})
