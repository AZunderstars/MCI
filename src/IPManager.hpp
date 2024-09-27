#pragma once
#ifndef IPMANAGER_HPP
#define IPMANAGER_HPP

#include "IP.hpp"
#include "AddressGroup.hpp"
#include <vector>
#include <string>
#include <iostream>

class IPManager
{
    public:
        void run();

    private:
        std::vector<IP> IPs;
        std::vector<AddressGroup *> address_groups;

        void create_address(std::string name, std::string value);
        void print_addresses(std::vector<std::string> command_sections);
        void print_address(IP ip, std::ostream &ostr = std::cout);
        void print_addresses_with_type(std::string type);
        void create_address_group(std::string name);
        void add_to_address_group(std::string address_group_name, std::string address_name);
        IP find_address_by_name(std::string name);
        AddressGroup *find_address_group_by_name(std::string name);
        void print_address_by_name(std::string name);
        void export_addresses_to_file(std::string file_name);
        void import_addresses_from_file(std::string file_name);
};

#endif
