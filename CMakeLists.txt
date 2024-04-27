cmake_minimum_required(VERSION 3.27)
project(course C)

set(CMAKE_C_STANDARD 11)

add_executable(course
        1056A.c)
add_executable(440A 440A.c)
add_executable(1039B 1039B.c)
add_executable(1166A 1166A.c)
add_executable(841A 841A.c)
add_executable(1025A 1025A.c)
add_executable(1011A 1011A.c
        libs/data_structures/vector/test2.c
        libs/files/1_task.c
        libs/files/2_task.c
        libs/files/3_task.c
        libs/files/4_task.c
        libs/files/5_task.c
        libs/files/6_task.c
        libs/files/7_task.c
        libs/files/8_task.c
        libs/files/9_task.c)
add_executable(37A 37A.c)
add_executable(1020B 1020B.c)
add_executable(672B 672B.c)
add_executable(777B 777B.c)
add_executable(131B 131B.c)
add_executable(main main.c)
add_executable(main2 main2.c)
add_executable(test test.c
        libs/data_structures/vector/test2.c)

add_subdirectory(libs)
target_link_libraries(course data_structures)
target_link_libraries(course algorithms)