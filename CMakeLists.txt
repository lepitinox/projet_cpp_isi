cmake_minimum_required(VERSION 3.21)
project(projet_cpp_isi)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -pedantic -pedantic-errors -O3")

add_executable(projet_cpp_isi
        main.cpp
        oklol.cpp
        oklol.h
        test.cpp
        test.h
        Generic_station_parser.hpp
        Grade.hpp
        Generic_connection_parser.hpp
        Generic_mapper.hpp
        last.cpp
        last.h
        base.cpp
        base.h
        )
