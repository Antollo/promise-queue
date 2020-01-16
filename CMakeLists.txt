cmake_minimum_required (VERSION 2.6)
set(CMAKE_CXX_STANDARD 17)
project(promise-queue)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-O3 -Wall)
endif()

add_executable(promise_queue main.cpp)

find_package(Threads REQUIRED)
target_link_libraries(promise_queue Threads::Threads)