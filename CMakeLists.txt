cmake_minimum_required(VERSION 3.12)
project(sparql-query VERSION 0.9.0)
set(CMAKE_CXX_STANDARD 17)

# installation directories
set(sparql-query_INSTALL_INCLUDE_DIR "include" CACHE STRING "The installation include directory")
set(sparql-query_INSTALL_CMAKE_DIR "share/sparql-query/cmake" CACHE STRING "The installation cmake directory")


# define a header-only library
add_library(sparql-query INTERFACE)
add_library(Dice::sparql-query ALIAS sparql-query)

target_include_directories(sparql-query INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${sparql-query_INSTALL_CMAKE_DIR}>
        )

# require C++17
target_compile_features(sparql-query INTERFACE cxx_std_20)

# Make package findable
configure_file(cmake/dummy-config.cmake.in sparql-query-config.cmake @ONLY)

# Enable version checks in find_package
include(CMakePackageConfigHelpers)
write_basic_package_version_file(sparql-query-config-version.cmake COMPATIBILITY SameMajorVersion)

# install and export target
install(TARGETS sparql-query EXPORT sparql-query-targets)

install(EXPORT sparql-query-targets
        FILE sparql-query-config.cmake
        NAMESPACE Dice::
        DESTINATION ${sparql-query_INSTALL_CMAKE_DIR}
        )

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/sparql-query-config-version.cmake DESTINATION ${sparql-query_INSTALL_CMAKE_DIR})
install(DIRECTORY include/ DESTINATION ${sparql-query_INSTALL_INCLUDE_DIR})


# testing
option(sparql-Query_BUILD_TESTS "Build sparql-Query tests." ON)
#if(sparql-Query_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
#endif()