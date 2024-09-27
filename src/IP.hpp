#pragma once
#ifndef IP_HPP
#define IP_HPP

#include "IPValue.hpp"
#include <string>

class IP
{
    public:
        IP(std::string value);

    protected:
        IPValue value;
};

#endif
