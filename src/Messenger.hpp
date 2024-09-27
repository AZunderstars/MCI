#pragma once
#ifndef MESSENGER_HPP
#define MESSENGER_HPP

#include "IP.hpp"
#include "AddressGroup.hpp"
#include <vector>
#include <string>
#include <iostream>

class Messenger
{
    public:
        void output_create_address_success(IP ip);
        void output_print_addresses(std::vector<IP> IPs);
        void output_print_addresses_with_type(std::vector<IP> IPs, std::string type);
        void output_print_address_groups(std::vector<AddressGroup *> address_groups);
        void output_create_address_group_success(AddressGroup *address_group);
        void output_add_to_address_group_success(AddressGroup *address_group, IP ip);
        void output_get_address_by_name(IP ip);
        void output_export_file_success();
        void output_import_file_success();
        void print_address(IP ip, std::ostream &ostr = std::cout);
        void output_create_address_fail(std::string value);
        void output_address_group_not_found(std::string name);
        void output_ip_not_found(std::string name);
        void output_address_already_in_address_group(AddressGroup *address_group, IP ip);
};
#endif
