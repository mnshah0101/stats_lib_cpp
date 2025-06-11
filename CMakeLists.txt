cmake_minimum_required(VERSION 3.10)
project(stats_lib VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define library sources
set(SOURCES
    src/distributions.cpp
    src/estimation.cpp
    src/rng.cpp
    src/sampling.cpp
)

# Create the library
add_library(stats_lib ${SOURCES})

# Set include directories
target_include_directories(stats_lib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Set compile options
target_compile_options(stats_lib PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -pedantic>
)

# Installation settings
include(GNUInstallDirs)

# Install the library
install(TARGETS stats_lib
    EXPORT stats_libTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Install the headers
install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Export the targets
install(EXPORT stats_libTargets
    FILE stats_libTargets.cmake
    NAMESPACE stats_lib::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/stats_lib
)

# Create and install the config file
include(CMakePackageConfigHelpers)
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/stats_lib-config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/stats_lib-config.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/stats_lib
)

# Create and install the version file
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/stats_lib-config-version.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

# Install the config and version files
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/stats_lib-config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/stats_lib-config-version.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/stats_lib
)

# Add option to build examples
option(BUILD_EXAMPLES "Build example programs" OFF)
if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

# Add option to build tests
option(BUILD_TESTS "Build test programs" ON)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
