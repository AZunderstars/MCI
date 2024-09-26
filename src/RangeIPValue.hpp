#pragma once
#ifndef RANGEIPVALUE_HPP
#define RANGEIPVALUE_HPP

#include "IPValue.hpp"
#include <string>

class RangeIPValue : public IPValue
{
public:
    RangeIPValue(std::string _value);

protected:
    std::string value;
};

#endif
