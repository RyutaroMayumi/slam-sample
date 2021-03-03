cmake_minimum_required(VERSION 3.14)
project(slam-sample-test)


# setup google test
include(tools/DownloadProject/DownloadProject.cmake)
download_project(
    PROJ googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG master
    UPDATE_DISCONNECTED 1
)
add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})


# set test target
include_directories(../include)
add_library(SampleClass ../source/SampleClass.cpp)
add_executable(SampleClass-test ./src/SampleClass_test.cpp)
target_link_libraries(SampleClass-test
    SampleClass
    gtest_main
)


# run test
enable_testing()    # needed for make test
include(GoogleTest) # needed for gtest_discover_tests()
gtest_discover_tests(SampleClass-test)
