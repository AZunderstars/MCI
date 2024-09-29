#pragma once
#ifndef ADDRESSGROUP_HPP
#define ADDRESSGROUP_HPP

#include "Address.hpp"
#include <string>
#include <vector>

class AddressGroup
{
    public:
        AddressGroup(std::string _name);
        std::string get_name() const;
        std::vector<Address> get_addresses();
        void add_address(Address address);
        bool has_address(Address address);

    private:
        std::string name;
        std::vector<Address> addresses;
};

#endif
