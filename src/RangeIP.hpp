#pragma once
#ifndef RANGEIP_HPP
#define RANGEIP_HPP

#include "IP.hpp"
#include <string>

class RangeIP : public IP
{
    public:
        RangeIP() = default;
        RangeIP(std::string _value);
        std::string get_type();
};

#endif
