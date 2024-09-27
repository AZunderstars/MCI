#include "AddressGroup.hpp"

using namespace std;

AddressGroup::AddressGroup(string _name)
{
    name = _name;
}

string AddressGroup::get_name()
{
    return name;
}
