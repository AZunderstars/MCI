#pragma once
#ifndef ADDRESSMANAGER_HPP
#define ADDRESSMANAGER_HPP

#include "Address.hpp"
#include "AddressGroup.hpp"
#include "Messenger.hpp"
#include <vector>
#include <string>

class AddressManager
{
    public:
        void run();

    private:
        std::vector<Address> addresses;
        std::vector<AddressGroup *> address_groups;
        Messenger messenger;

        void create_address(std::string name, std::string ip_value);
        void print_addresses(std::vector<std::string> command_sections);
        void print_addresses_with_type(std::string type);
        void create_address_group(std::string name);
        void add_to_address_group(std::string address_group_name, std::string address_name);
        std::vector<Address>::iterator find_address_by_name(std::string name);
        std::vector<AddressGroup *>::iterator find_address_group_by_name(std::string name);
        void print_address_by_name(std::string name);
        void export_addresses_to_file(std::string file_name);
        void import_addresses_from_file(std::string file_name);
};

#endif
