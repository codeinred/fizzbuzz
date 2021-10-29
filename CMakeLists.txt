cmake_minimum_required(VERSION 3.14)

project(
    "fizzbuzz"
    VERSION 0.0.1
    DESCRIPTION "HPC FizzBuzz"
    HOMEPAGE_URL "https://github.com/codeinred/fizzbuzz"
    LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
include(helper)
include(installation)

option(
    BUILD_TESTING
    "Build testing for ${PROJECT_NAME}"
    OFF)


find_or_fetch(
    fmt
    https://github.com/fmtlib/fmt.git
    master)
add_source_dir(src fmt)

if(PROJECT_IS_TOP_LEVEL AND BUILD_TESTING)

    # Download the Catch2 library, version >3.0.0
    find_or_fetch(
        Catch2
        https://github.com/catchorg/catch2.git
        devel
        3.0.0)
    FetchContent_MakeAvailable(${remote_dependencies})

    add_executable(
        test_project
        test/test_project.cpp)
    target_link_libraries(
        test_project
        Catch2::Catch2WithMain)

    list(APPEND CMAKE_MODULE_PATH ${CMAKE_INSTALL_PREFIX}/lib/cmake/Catch2)
    list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
    include(CTest)
    include(Catch)
    catch_discover_tests(test_project)
else()
    FetchContent_MakeAvailable(${remote_dependencies})
endif()
