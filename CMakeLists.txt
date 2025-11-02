cmake_minimum_required(VERSION 3.10)
project(GeometryFigures VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

set(MAIN_SOURCE
    src/main.cpp
)

set(LIB_SOURCES
    src/Point.cpp
    src/figure.cpp
    src/vector_Points.cpp
    src/vector_figure.cpp
    src/square.cpp
    src/rectangle.cpp
    src/trapezoid.cpp
)

set(HEADERS
    include/Point.h
    include/figure.h
    include/vector_Points.h
    include/vector-figure.h
    include/square.h
    include/rectangle.h
    include/trapezoid.h
)


add_executable(geometry_figures ${MAIN_SOURCE} ${LIB_SOURCES} ${HEADERS})
target_include_directories(geometry_figures PRIVATE include)
target_compile_features(geometry_figures PRIVATE cxx_std_20)


set(TEST_SOURCES
    tests/main_test.cpp
    tests/test_point.cpp
    tests/test_vector.cpp
    tests/test_figures.cpp
)

add_executable(run_tests ${TEST_SOURCES} ${LIB_SOURCES})
target_include_directories(run_tests PRIVATE include)
target_compile_features(run_tests PRIVATE cxx_std_20)
target_link_libraries(run_tests PRIVATE GTest::gtest_main)

enable_testing()
add_test(NAME GeometryTests COMMAND run_tests)