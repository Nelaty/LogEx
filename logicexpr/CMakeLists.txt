file(GLOB_RECURSE source_files "*.h" "*.cpp")

add_library(${PROJECT_NAME} STATIC ${source_files})
target_include_directories(${PROJECT_NAME} PUBLIC ${LE_INCLUDE_DIRECTORIES})
target_link_libraries(${PROJECT_NAME} args spdlog)