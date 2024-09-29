#pragma once
#ifndef IP_HPP
#define IP_HPP

#include <string>

class IP
{
    public:
        virtual std::string get_type() { return ""; };
        std::string get_value();

    protected:
        std::string value;
};
#endif
