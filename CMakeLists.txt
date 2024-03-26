cmake_minimum_required(VERSION 3.2)
project(HomeWorkPatterns-1)

set (SOURCES HomeWorkPatterns-1.cpp sql_query_builder.cpp)
set (HEADERS sql_query_builder.h)

add_executable(HomeWorkPatterns-1 ${SOURCES} ${HEADERS})