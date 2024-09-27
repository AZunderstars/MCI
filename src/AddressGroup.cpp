#include "AddressGroup.hpp"
#include <algorithm>

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

bool AddressGroup::has_address(IP ip)
{
    return find(IPs.begin(), IPs.end(), ip) != IPs.end();
}
