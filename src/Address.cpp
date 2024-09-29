#include "Address.hpp"

using namespace std;

Address::Address(string _name, IP *_ip)
{
    name = _name;
    ip = _ip;
}

string Address::get_ip_value_type()
{
    return ip->get_type();
}

string Address::get_ip_value()
{
    return ip->get_value();
}

string Address::get_name() const
{
    return name;
}

bool Address::operator==(const Address &other)
{
    return name == other.name;
}
