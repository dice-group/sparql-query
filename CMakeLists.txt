cmake_minimum_required(VERSION 3.12)
project(sparql-queryGraph VERSION 0.9.0)
set(CMAKE_CXX_STANDARD 17)

# installation directories
set(sparql-queryGraph_INSTALL_INCLUDE_DIR "include" CACHE STRING "The installation include directory")
set(sparql-queryGraph_INSTALL_CMAKE_DIR "share/sparql-queryGraph/cmake" CACHE STRING "The installation cmake directory")


# define a header-only library
add_library(sparql-queryGraph INTERFACE)
add_library(Dice::sparql-queryGraph ALIAS sparql-queryGraph)

target_include_directories(sparql-queryGraph INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${sparql-queryGraph_INSTALL_CMAKE_DIR}>
        )

# require C++17
target_compile_features(sparql-queryGraph INTERFACE cxx_std_17)

# Make package findable
configure_file(cmake/dummy-config.cmake.in sparql-queryGraph-config.cmake @ONLY)

# Enable version checks in find_package
include(CMakePackageConfigHelpers)
write_basic_package_version_file(sparql-queryGraph-config-version.cmake COMPATIBILITY SameMajorVersion)

# install and export target
install(TARGETS sparql-queryGraph EXPORT sparql-queryGraph-targets)

install(EXPORT sparql-queryGraph-targets
        FILE sparql-queryGraph-config.cmake
        NAMESPACE Dice::
        DESTINATION ${sparql-queryGraph_INSTALL_CMAKE_DIR}
        )

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/sparql-queryGraph-config-version.cmake DESTINATION ${sparql-queryGraph_INSTALL_CMAKE_DIR})
install(DIRECTORY include/ DESTINATION ${sparql-queryGraph_INSTALL_INCLUDE_DIR})


# testing
#option(sparql-Query_BUILD_TESTS "Build sparql-Query tests." OFF)
#if(sparql-Query_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
#endif()