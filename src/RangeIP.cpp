#include "RangeIP.hpp"

using namespace std;

RangeIP::RangeIP(string _value)
{
    value = _value;
}

string RangeIP::get_type()
{
    return "range";
}
