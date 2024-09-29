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

vector<Address> AddressGroup::get_addresses()
{
    return addresses;
}

void AddressGroup::add_address(Address address)
{
    addresses.push_back(address);
}

bool AddressGroup::has_address(Address address)
{
    return find(addresses.begin(), addresses.end(), address) != addresses.end();
}
