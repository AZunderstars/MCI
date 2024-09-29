#pragma once
#ifndef MESSENGER_HPP
#define MESSENGER_HPP

#include "Address.hpp"
#include "AddressGroup.hpp"
#include <vector>
#include <string>
#include <iostream>

class Messenger
{
    public:
        void output_create_address_success(Address address);
        void output_print_addresses(std::vector<Address> addresses);
        void output_print_addresses_with_type(std::vector<Address> addresses, std::string type);
        void output_print_address_groups(std::vector<AddressGroup *> address_groups);
        void output_create_address_group_success(AddressGroup *address_group);
        void output_add_to_address_group_success(AddressGroup *address_group, Address address);
        void output_get_address_by_name(Address address);
        void output_export_file_success();
        void output_import_file_success();
        void print_address(Address address, std::ostream &ostr = std::cout);
        void output_create_address_fail(std::string value);
        void output_address_group_not_found(std::string name);
        void output_address_not_found(std::string name);
        void output_address_already_in_address_group(AddressGroup *address_group, Address address);
};
#endif
