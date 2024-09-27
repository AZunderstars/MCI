#include "AddressGroup.hpp"

using namespace std;

AddressGroup::AddressGroup(string _name)
{
    name = _name;
}

string AddressGroup::get_name() const
{
    return name;
}

vector<IP> AddressGroup::get_addresses()
{
    return IPs;
}

void AddressGroup::add_address(IP ip)
{
    IPs.push_back(ip);
}
