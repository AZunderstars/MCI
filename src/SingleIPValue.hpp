#pragma once
#ifndef SINGLEIPVALUE_HPP
#define SINGLEIPVALUE_HPP

#include "IPValue.hpp"
#include <string>

class SingleIPValue : public IPValue
{
    public:
        SingleIPValue(std::string _value);

    protected:
        std::string value;
};

#endif
