#pragma once
#ifndef ADDRESS_HPP
#define ADDRESS_HPP

#include "IP.hpp"
#include <string>

class Address
{
    public:
        Address() = default;
        Address(std::string _name, IP *_ip);
        std::string get_ip_value_type();
        std::string get_ip_value();
        std::string get_name() const;
        bool operator==(const Address& other);

    protected:
        IP *ip;
        std::string name;
};

#endif
