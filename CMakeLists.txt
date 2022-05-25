cmake_minimum_required(VERSION 3.21)
project(PRG2_L2 C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-std=c17 -Wall -Wconversion -Wextra -Wsign-conversion -pedantic")

add_executable(PRG2_L2 main.c calculs.c calculs.h voitures.c voitures.h taxes.c
        taxes.h affichage.c affichage.h)
