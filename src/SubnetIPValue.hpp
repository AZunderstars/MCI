#pragma once
#ifndef SUBNETIPVALUE_HPP
#define SUBNETIPVALUE_HPP

#include "IP.hpp"
#include <string>

class SubnetIPValue : public IP
{
    public:
        SubnetIPValue() = default;
        SubnetIPValue(std::string _value);
        std::string get_type();
};

#endif
