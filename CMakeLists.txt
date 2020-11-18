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

project(task_tracker)
add_executable(task_tracker w1/task_tracker.cpp)

project(all_square)
add_executable(all_square w1/all_square.cpp)

project(get_ref_strict)
add_executable(get_ref_strict w1/get_ref_strict.cpp)

project(decomp_correct)
add_executable(decomp_correct w2/decomposition/correct.cpp)

project(decomp_starter)
add_executable(decomp_starter w2/decomposition/starter.cpp)

#project(correct_decomp)
#add_executable(w2/decomposition/correct_decomp.cpp)

project(full_decomposition)
add_executable(full_decomposition w2/fulll_decomposition/main.cpp)

project(print_vector_part)
add_executable(print_vector_part w2/printVectorPart.cpp)

project(set_part)
add_executable(set_part w2/set_part.cpp)

project(word_split)
add_executable(word_split w2/word_split.cpp)

project(remove_duplicates)
add_executable(remove_duplicates w2/iterators/remove_duplicates.cpp)
