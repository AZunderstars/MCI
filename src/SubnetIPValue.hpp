#pragma once
#ifndef SUBNETIPVALUE_HPP
#define SUBNETIPVALUE_HPP

#include "IPValue.hpp"
#include <string>

class SubnetIPValue : public IPValue
{
    public:
        SubnetIPValue() = default;
        SubnetIPValue(std::string _value);

    protected:
        std::string value;
};

#endif
