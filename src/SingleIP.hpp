#pragma once
#ifndef SINGLEIP_HPP
#define SINGLEIP_HPP

#include "IP.hpp"
#include <string>

class SingleIP : public IP
{
    public:
        SingleIP() = default;
        SingleIP(std::string _value);
        std::string get_type();
};

#endif
