cmake_minimum_required(VERSION 3.10)

project(test-framework
    VERSION 0.1.0
    LANGUAGES C
)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

#######################################
# Library
#######################################

add_library(my_test_framework SHARED
    src/assertions.c
    src/registry.c
    src/reporter.c
    src/runner.c
    src/test_internal.c
)

# Public include directory
target_include_directories(my_test_framework
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>

    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/internal
)

# Exported target name
set_target_properties(my_test_framework PROPERTIES
    EXPORT_NAME my_test_framework
)

#######################################
# Example
#######################################

add_executable(test_framework
    example/simple_test.c
)

target_link_libraries(test_framework
    PRIVATE
        my_test_framework
)

#######################################
# Installation
#######################################

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# Install library
install(
    TARGETS my_test_framework
    EXPORT my_test_frameworkTargets

    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Install public headers
install(
    DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Export targets
install(
    EXPORT my_test_frameworkTargets
    FILE my_test_frameworkTargets.cmake
    NAMESPACE my_test_framework::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/my_test_framework
)

# Generate Config.cmake
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/my_test_frameworkConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/my_test_frameworkConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/my_test_framework
)

# Generate ConfigVersion.cmake
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/my_test_frameworkConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

# Install package configuration files
install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/my_test_frameworkConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/my_test_frameworkConfigVersion.cmake
    DESTINATION
        ${CMAKE_INSTALL_LIBDIR}/cmake/my_test_framework
)
