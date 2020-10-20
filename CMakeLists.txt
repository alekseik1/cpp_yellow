cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Werror -Wall)

project(Matrix VERSION 0.1)
add_executable(matrix matrix/matrix.cpp)

project(Matrix_coursera VERSION 1.0)
add_executable(matrix_coursera matrix/matrix_coursera.cpp)

project(lecture1)
add_executable(lecture_1 lecture_1.cpp)
