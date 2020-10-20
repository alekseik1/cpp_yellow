cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall)

project(Matrix VERSION 0.1)
add_executable(matrix matrix/matrix.cpp)

project(Matrix_coursera VERSION 1.0)
add_executable(matrix_coursera matrix/matrix_coursera.cpp)

project(lecture1)
add_executable(lecture_1 w1/lecture_1.cpp)

project(mean_temperature)
add_executable(mean_temperature w1/mean_temperature.cpp)

project(blocks)
add_executable(blocks w1/blocks.cpp)

project(region_base)
add_executable(region_base w1/base.cpp)
