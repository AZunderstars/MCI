#pragma once
#ifndef IP_HPP
#define IP_HPP

#include "IPValue.hpp"
#include <string>

class IP
{
    public:
        IP() = default;
        IP(std::string _name, IPValue *_IPvalue);
        std::string get_value_type();
        std::string get_value();
        std::string get_name() const;
        bool operator==(const IP& other);

    protected:
        IPValue *IPvalue;
        std::string name;
};

#endif
