cmake_minimum_required(VERSION 3.10.0) 
project(test-framework VERSION 0.1.0 LANGUAGES C) 

add_executable(test_framework src/main.c)

target_include_directories(test_framework
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)
