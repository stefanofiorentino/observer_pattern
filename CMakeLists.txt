cmake_minimum_required(VERSION 3.14)
project(observer_pattern)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(TARGET_NAME observer_pattern)

set(PROJECT_CMAKE_IN ${observer_pattern_SOURCE_DIR}/cmake/in)
set(PROJECT_DEPS_DIR ${observer_pattern_SOURCE_DIR}/deps)
set(PROJECT_SRC_DIR  ${observer_pattern_SOURCE_DIR}/src)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

set(THREADS_PREFER_PTHREAD_FLAG ON)
include(FindThreads)

#
# Testing
#
set(BUILD_TESTING OFF)
set(GOOGLETEST_DEPS_DIR ${PROJECT_DEPS_DIR}/googletest)

configure_file(${PROJECT_CMAKE_IN}/deps.in ${PROJECT_DEPS_DIR}/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" . WORKING_DIRECTORY ${PROJECT_DEPS_DIR})
execute_process(COMMAND ${CMAKE_COMMAND} --build . WORKING_DIRECTORY ${PROJECT_DEPS_DIR})

# gtest, gtest_main, gmock and gmock_main targets are available from now on
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(${GOOGLETEST_DEPS_DIR})

set(BUILD_TESTING ON)
enable_testing()

add_subdirectory(test)