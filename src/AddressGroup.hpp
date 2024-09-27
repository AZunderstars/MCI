#pragma once
#ifndef ADDRESSGROUP_HPP
#define ADDRESSGROUP_HPP

#include "IP.hpp"
#include <string>
#include <vector>

class AddressGroup
{
    public:
        std::string get_name();
    private:
        std::string name;
        std::vector<IP>IPs;
};

#endif
