#include "Address.hpp"

using namespace std;

Address::Address(string _name, IPValue *_IPvalue)
{
    name = _name;
    IPvalue = _IPvalue;
}

string Address::get_value_type()
{
    return IPvalue->get_type();
}

string Address::get_value()
{
    return IPvalue->get_value();
}

string Address::get_name() const
{
    return name;
}

bool Address::operator==(const Address &other)
{
    return name == other.name;
}
