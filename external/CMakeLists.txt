include(CPM)

########################################
# Third party dependencies
########################################

if(NOT TARGET spdlog)
    CPMAddPackage(
            NAME spdlog
            GIT_REPOSITORY https://github.com/gabime/spdlog
            GIT_TAG v1.9.2
    )
endif()

if(NOT TARGET args)
    CPMAddPackage(
            NAME args
            GIT_REPOSITORY https://github.com/Taywee/args
            GIT_TAG 6.3.0
    )
endif()

if(NOT TARGET Catch2)
    CPMAddPackage(
            NAME Catch2
            GIT_REPOSITORY https://github.com/catchorg/Catch2
            GIT_TAG v2.13.8
    )
endif()

if(NOT TARGET gsl)
    CPMAddPackage(
            NAME gsl
            GIT_REPOSITORY https://github.com/microsoft/GSL
            GIT_TAG v4.0.0
    )
endif()

