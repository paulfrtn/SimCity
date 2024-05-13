cmake_minimum_required(VERSION 3.28)
project(BullyCity_FINAL C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(BullyCity_FINAL
        fonctions.c
        header.h
        main.c)

target_link_libraries(BullyCity_FINAL -lmingw32 -lalleg44)