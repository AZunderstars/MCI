#include "IPManager.hpp"
#include "utils.hpp"
#include "SingleIPValue.hpp"
#include "SubnetIPValue.hpp"
#include "RangeIPValue.hpp"
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

void IPManager::run()
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

void IPManager::create_address(string name, string value)
{
    IP ip;
    if (is_single_IP_value_valid(value))
    {
        ip = IP(name, new SingleIPValue(value));
    }
    else if (is_subnet_IP_value_valid(value))
    {
        ip = IP(name, new SubnetIPValue(value));
    }
    else if (is_range_IP_value_valid(value))
    {
        ip = IP(name, new RangeIPValue(value));
    }
    else
    {
        cout << "error " << value << " is not valid" << endl;
        return;
    }
    IPs.push_back(ip);
    messenger.output_create_address_success(ip);
}

void IPManager::print_addresses(vector<string> command_sections)
{
    if (command_sections.size() == 1)
    {
        messenger.output_print_addresses(IPs);
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

void IPManager::print_addresses_with_type(string type)
{
    vector<IP> selected_IPs;
    for (IP ip : IPs)
    {
        if (type == ip.get_value_type())
        {
            selected_IPs.push_back(ip);
        }
    }
    messenger.output_print_addresses_with_type(selected_IPs, type);
}

void IPManager::create_address_group(string name)
{
    AddressGroup *address_group = new AddressGroup(name);
    address_groups.push_back(address_group);
    messenger.output_create_address_group_success(address_group);
}

IP IPManager::find_address_by_name(string name)
{
    auto iter = find_if(IPs.begin(), IPs.end(), [&name](const IP &ip)
                        { return ip.get_name() == name; });
    return IPs[distance(IPs.begin(), iter)];
}

AddressGroup *IPManager::find_address_group_by_name(string name)
{
    auto iter = find_if(address_groups.begin(), address_groups.end(), [&name](const AddressGroup *ag)
                        { return ag->get_name() == name; });
    return address_groups[distance(address_groups.begin(), iter)];
}

void IPManager::add_to_address_group(string address_group_name, string address_name)
{
    AddressGroup *address_group = find_address_group_by_name(address_group_name);
    IP ip = find_address_by_name(address_name);
    address_group->add_address(ip);
    messenger.output_add_to_address_group_success(address_group, ip);
}

void IPManager::print_address_by_name(string name)
{
    IP ip = find_address_by_name(name);
    messenger.output_get_address_by_name(ip);
}

void IPManager::export_addresses_to_file(string file_name)
{
    ofstream file;
    file.open(file_name);
    for (IP ip : IPs)
    {
        messenger.print_address(ip, file);
    }
    file.close();
    messenger.output_export_file_success();
}

void IPManager::import_addresses_from_file(string file_name)
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
