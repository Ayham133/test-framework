cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

project(test-framework
    VERSION 0.1.0
    LANGUAGES C
)

# Build the library
add_library(my_test_framework SHARED
    src/assertions.c
    src/registry.c
    src/reporter.c
    src/runner.c
    src/test_internal.c
)

# Public API
target_include_directories(my_test_framework
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include

    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/internal
)

# Example program
add_executable(test_framework
    example/simple_test.c
)

target_link_libraries(test_framework
    PRIVATE
        my_test_framework
)
