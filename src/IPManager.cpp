#include "IPManager.hpp"
#include "utils.hpp"
#include "SingleIPValue.hpp"
#include "SubnetIPValue.hpp"
#include "RangeIPValue.hpp"
#include <string>
#include <iostream>

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
    cout << value << " added to list" << endl;
}

void IPManager::print_addresses(vector<string> command_sections)
{
    if (command_sections.size() == 1)
    {
        print_addresses_in(IPs);
    }
    else
    {
        print_addresses_with_type(command_sections[1]);
    }
}

void IPManager::print_addresses_in(vector<IP> ips)
{
    for (IP ip : ips)
    {
        cout << ip.get_name() << " " << ip.get_value() << endl;
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
    print_addresses_in(selected_IPs);
}

void IPManager::create_address_group(string name)
{
    address_groups.push_back(AddressGroup(name));
}

void IPManager::add_to_address_group(string address_group_name, string address_name)
{
    
}
