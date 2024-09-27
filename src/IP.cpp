#include "IP.hpp"

using namespace std;

IP::IP(IPValue *_IPvalue)
{
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
