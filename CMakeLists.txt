cmake_minimum_required(VERSION 3.13)
project(Sparql-Query VERSION 0.9.0)
set(CMAKE_CXX_STANDARD 17)


# define a header-only library
add_library(Sparql-Query INTERFACE)
add_library(Dice::Sparql-Query ALIAS Sparql-Query)


add_executable(main main.cpp)
target_link_libraries(main Sparql-Query)