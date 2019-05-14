cmake_minimum_required(VERSION 3.13)
project(clisp)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(main src/main.cpp src/clisp/exp.cpp src/clisp/exp.h src/clisp/parser.cpp src/clisp/parser.h)

target_compile_options(main PUBLIC -Wall -Wextra)
target_compile_features(main PRIVATE cxx_std_17)
