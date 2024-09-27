#pragma once
#ifndef ADDRESSGROUP_HPP
#define ADDRESSGROUP_HPP

#include "IP.hpp"
#include <string>
#include <vector>

class AddressGroup
{
    public:
        AddressGroup(std::string _name);
        std::string get_name() const;
        std::vector<IP> get_addresses();
        void add_address(IP ip);

    private:
        std::string name;
        std::vector<IP> IPs;
};

#endif
