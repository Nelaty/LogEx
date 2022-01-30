#include "logex/api.h"
#include "cmake/config.h"

#include <sstream>

namespace logex
{
    Version Version::library()
    {
        Version version{};
        std::istringstream(LOGEX_LIBRARY_VERSION_MAJOR) >> version.mMajor;
        std::istringstream(LOGEX_LIBRARY_VERSION_MINOR) >> version.mMajor;
        std::istringstream(LOGEX_LIBRARY_VERSION_PATCH) >> version.mMajor;
        return version;
    }

    std::string Version::libraryString()
    {
        return LOGEX_LIBRARY_VERSION;
    }
}