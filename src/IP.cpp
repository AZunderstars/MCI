#include "IP.hpp"

using namespace std;

IP::IP(string _name, IPValue *_IPvalue)
{
    name = _name;
    IPvalue = _IPvalue;
}

string IP::get_value_type()
{
    return IPvalue->get_type();
}

string IP::get_value()
{
    return IPvalue->get_value();
}

string IP::get_name()
{
    return name;
}
