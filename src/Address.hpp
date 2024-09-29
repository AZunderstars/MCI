#pragma once
#ifndef ADDRESS_HPP
#define ADDRESS_HPP

#include "IPValue.hpp"
#include <string>

class Address
{
    public:
        Address() = default;
        Address(std::string _name, IPValue *_IPvalue);
        std::string get_value_type();
        std::string get_value();
        std::string get_name() const;
        bool operator==(const Address& other);

    protected:
        IPValue *IPvalue;
        std::string name;
};

#endif
