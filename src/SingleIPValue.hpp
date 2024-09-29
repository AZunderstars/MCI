#pragma once
#ifndef SINGLEIPVALUE_HPP
#define SINGLEIPVALUE_HPP

#include "IP.hpp"
#include <string>

class SingleIPValue : public IP
{
    public:
        SingleIPValue() = default;
        SingleIPValue(std::string _value);
        std::string get_type();
};

#endif
