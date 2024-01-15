cmake_minimum_required(VERSION 3.27)
project(HangMan)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HangMan
        Korisnik.cpp
        Korisnik.h
        main.cpp
        Osoba.cpp
        Osoba.h
        Rijec.h
        Rijec.cpp
        Trial.h
        Trial.cpp)
