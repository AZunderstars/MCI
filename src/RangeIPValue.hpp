#pragma once
#ifndef RANGEIPVALUE_HPP
#define RANGEIPVALUE_HPP

#include "IP.hpp"
#include <string>

class RangeIPValue : public IP
{
    public:
        RangeIPValue() = default;
        RangeIPValue(std::string _value);
        std::string get_type();
};

#endif
