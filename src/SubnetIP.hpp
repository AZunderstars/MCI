#pragma once
#ifndef SUBNETIP_HPP
#define SUBNETIP_HPP

#include "IP.hpp"
#include <string>

class SubnetIP : public IP
{
    public:
        SubnetIP() = default;
        SubnetIP(std::string _value);
        std::string get_type();
};

#endif
