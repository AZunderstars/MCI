#include "SubnetIPValue.hpp"

using namespace std;

SubnetIPValue::SubnetIPValue(string _value)
{
    value = _value;
}

string SubnetIPValue::get_type()
{
    return "subnet";
}
