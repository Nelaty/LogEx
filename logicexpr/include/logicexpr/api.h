#pragma once

#include <string>

class Version
{
public:

    static constexpr int api(){ return 1; }
    static std::string library();
};