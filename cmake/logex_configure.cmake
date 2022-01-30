function(logex_configure_version)
    set(LOGEX_LIBRARY_VERSION "std::string(\"${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}\")" PARENT_SCOPE)
    set(LOGEX_LIBRARY_VERSION_MAJOR "std::string(\"${PROJECT_VERSION_MAJOR}\")" PARENT_SCOPE)
    set(LOGEX_LIBRARY_VERSION_MINOR "std::string(\"${PROJECT_VERSION_MINOR}\")" PARENT_SCOPE)
    set(LOGEX_LIBRARY_VERSION_PATCH "std::string(\"${PROJECT_VERSION_PATCH}\")" PARENT_SCOPE)
endfunction()

function(logex_configure_files)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.h.in
            ${CMAKE_CURRENT_SOURCE_DIR}/logex/src/cmake/config.h
            @ONLY)
endfunction()