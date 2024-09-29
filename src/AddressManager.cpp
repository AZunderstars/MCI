#include "AddressManager.hpp"
#include "utils.hpp"
#include "SingleIPValue.hpp"
#include "SubnetIPValue.hpp"
#include "RangeIPValue.hpp"
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

void AddressManager::run()
{
    string command;
    while (getline(cin, command))
    {
        vector<string> command_sections = parse_string_by_delimiter(command, ' ');
        if (command_sections[0] == "address")
        {
            create_address(command_sections[1], command_sections[2]);
        }
        else if (command_sections[0] == "print")
        {
            print_addresses(command_sections);
        }
        else if (command_sections[0] == "createAddressGroup")
        {
            create_address_group(command_sections[1]);
        }
        else if (command_sections[0] == "addAddressGroup")
        {
            add_to_address_group(command_sections[1], command_sections[2]);
        }
        else if (command_sections[0] == "getAddress")
        {
            print_address_by_name(command_sections[1]);
        }
        else if (command_sections[0] == "exportFile")
        {
            export_addresses_to_file(command_sections[1]);
        }
        else if (command_sections[0] == "importFile")
        {
            import_addresses_from_file(command_sections[1]);
        }
    }
}

void AddressManager::create_address(string name, string value)
{
    Address address;
    if (is_single_IP_value_valid(value))
    {
        address = Address(name, new SingleIPValue(value));
    }
    else if (is_subnet_IP_value_valid(value))
    {
        address = Address(name, new SubnetIPValue(value));
    }
    else if (is_range_IP_value_valid(value))
    {
        address = Address(name, new RangeIPValue(value));
    }
    else
    {
        messenger.output_create_address_fail(value);
        return;
    }
    addresses.push_back(address);
    messenger.output_create_address_success(address);
}

void AddressManager::print_addresses(vector<string> command_sections)
{
    if (command_sections.size() == 1)
    {
        messenger.output_print_addresses(addresses);
    }
    else if (command_sections[1] == "groups")
    {
        messenger.output_print_address_groups(address_groups);
    }
    else
    {
        print_addresses_with_type(command_sections[1]);
    }
}

void AddressManager::print_addresses_with_type(string type)
{
    vector<Address> selected_addresses;
    for (Address address : addresses)
    {
        if (type == address.get_value_type())
        {
            selected_addresses.push_back(address);
        }
    }
    messenger.output_print_addresses_with_type(selected_addresses, type);
}

void AddressManager::create_address_group(string name)
{
    AddressGroup *address_group = new AddressGroup(name);
    address_groups.push_back(address_group);
    messenger.output_create_address_group_success(address_group);
}

vector<Address>::iterator AddressManager::find_address_by_name(string name)
{
    return find_if(addresses.begin(), addresses.end(), [&name](const Address &address)
                   { return address.get_name() == name; });
}

vector<AddressGroup *>::iterator AddressManager::find_address_group_by_name(string name)
{
    return find_if(address_groups.begin(), address_groups.end(), [&name](const AddressGroup *ag)
                   { return ag->get_name() == name; });
}

void AddressManager::add_to_address_group(string address_group_name, string address_name)
{
    auto iter_adress_group = find_address_group_by_name(address_group_name);
    if (iter_adress_group == address_groups.end())
    {
        messenger.output_address_group_not_found(address_group_name);
        return;
    }
    AddressGroup *address_group = *iter_adress_group;
    auto iter_address = find_address_by_name(address_name);
    if (iter_address == addresses.end())
    {
        messenger.output_address_not_found(address_name);
        return;
    }
    Address address = *iter_address;
    if (address_group->has_address(address))
    {
        messenger.output_address_already_in_address_group(address_group, address);
        return;
    }
    address_group->add_address(address);
    messenger.output_add_to_address_group_success(address_group, address);
}

void AddressManager::print_address_by_name(string name)
{
    Address address = *find_address_by_name(name);
    messenger.output_get_address_by_name(address);
}

void AddressManager::export_addresses_to_file(string file_name)
{
    ofstream file;
    file.open(file_name);
    for (Address address : addresses)
    {
        messenger.print_address(address, file);
    }
    file.close();
    messenger.output_export_file_success();
}

void AddressManager::import_addresses_from_file(string file_name)
{
    ifstream file(file_name);
    string name, value;
    while (file >> name >> value)
    {
        create_address(name, value);
    }
    file.close();
    messenger.output_import_file_success();
}
