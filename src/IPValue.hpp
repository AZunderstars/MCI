#pragma once
#ifndef IPVALUE_HPP
#define IPVALUE_HPP

#include <string>

class IPValue
{
    public:
        virtual std::string get_type() { return ""; };
        std::string get_value();

    protected:
        std::string value;
};
#endif
