#pragma once
#ifndef IPMANAGER_HPP
#define IPMANAGER_HPP

#include "IP.hpp"
#include "AddressGroup.hpp"
#include <vector>
#include <string>

class IPManager
{
    public:
        void run();

    protected:
        std::vector<IP> IPs;
        std::vector<AddressGroup> address_groups;

        void create_address(std::string name, std::string value);
        void print_addresses(std::vector<std::string> command_sections);
        void print_addresses_in(std::vector<IP> ips);
        void print_addresses_with_type(std::string type);
};

#endif
