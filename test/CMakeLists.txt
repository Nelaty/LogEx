file(GLOB_RECURSE source_files "*.h" "*.cpp")

add_executable(${PROJECT_NAME}_unittests ${source_files})
target_include_directories(${PROJECT_NAME}_unittests PUBLIC ${LE_INCLUDE_DIRECTORIES})
target_link_libraries(${PROJECT_NAME}_unittests ${LE_DEPENDENCIES} Catch2)