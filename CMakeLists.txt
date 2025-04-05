cmake_minimum_required(VERSION 3.30)
project(TAD_Circulo C)

set(CMAKE_C_STANDARD 11)

add_executable(TAD_Circulo main.c
        Circulo.h
        Ponto.h
        Ponto.c
        Circulo.c)

target_link_libraries(TAD_Circulo m)
