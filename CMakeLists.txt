cmake_minimum_required(VERSION 3.15)
project(untitled C)

set(CMAKE_C_STANDARD 99)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)


add_executable(OS_Lab10_Q1 Q1.c)
add_executable(OS_Lab10_Q2 Q2.c)
add_executable(OS_Lab10_Q3 Q3.c)
add_executable(OS_Lab10_Q4 Q4.c)

target_link_libraries(OS_Lab10_Q1 Threads::Threads)
target_link_libraries(OS_Lab10_Q2 Threads::Threads)
target_link_libraries(OS_Lab10_Q3 Threads::Threads)
target_link_libraries(OS_Lab10_Q4 Threads::Threads)
