#include "RangeIPValue.hpp"

using namespace std;

RangeIPValue::RangeIPValue(string _value)
{
    value = _value;
}

string RangeIPValue::get_type()
{
    return "range";
}
