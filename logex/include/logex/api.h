#pragma once
#include <string>

namespace logex
{
    class Version
    {
    public:
        static constexpr int api() { return 1; }

        static Version library();
        static std::string libraryString();

        std::uint16_t mMajor;
        std::uint16_t mMinor;
        std::uint16_t mPatch;
    };
}