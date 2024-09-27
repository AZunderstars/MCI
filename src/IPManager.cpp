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
            create_address(command_sections[1]);
        }
        else if (command_sections[0] == "print")
        {
            print_addresses(command_sections);
        }
    }
}

void IPManager::create_address(string value)
{
    IP ip;
    if (is_single_IP_value_valid(value))
    {
        ip = IP(SingleIPValue(value));
    }
    else if (is_subnet_IP_value_valid(value))
    {
        ip = IP(SubnetIPValue(value));
    }
    else if (is_range_IP_value_valid(value))
    {
        ip = IP(RangeIPValue(value));
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
        print_all_addresses();
    }
    else
    {
        print_addresses_with_type(command_sections[1]);
    }
}

void IPManager::print_all_addresses()
{
}

void IPManager::print_addresses_with_type(string type)
{
}
