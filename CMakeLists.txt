cmake_minimum_required(VERSION 3.25)
project(CGames C)

set(CMAKE_C_STANDARD 99)

add_executable(CGames main.c ticTacToe.c ticTacToe.h cardGame.c)
