#pragma once
#ifndef IP_HPP
#define IP_HPP

#include "IPValue.hpp"
#include <string>

class IP
{
    public:
        IP() = default;
        IP(IPValue *_IPvalue);
        std::string get_value_type();
        std::string get_value();

    protected:
        IPValue *IPvalue;
};

#endif
