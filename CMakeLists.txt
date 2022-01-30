cmake_minimum_required(VERSION 3.14)
project(logex VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)

# Cmake setup
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")
include(logex_configure)
logex_configure_version()
logex_configure_files()

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(LE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/logex/include/)
set(LE_DEPENDENCIES ${PROJECT_NAME} args spdlog)

# Add sources
add_subdirectory(external)
add_subdirectory(logex)

add_subdirectory(samples)
add_subdirectory(test)



