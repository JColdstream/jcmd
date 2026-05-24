cmake_minimum_required(VERSION 3.15..4.1)

project(jcmd VERSION 1.0
  DESCRIPTION "My molecular dynamics playground for having lots and lots of fun"
  LANGUAGES CXX)

add_library(atoms STATIC src/atoms.cpp)
add_library(lj_cut STATIC src/forcefields/lj_cut.cpp)

add_executable(jcmd ./src/jcmd.cpp)

target_link_libraries(jcmd PRIVATE atoms lj_cut)


