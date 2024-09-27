#include "SingleIPValue.hpp"

using namespace std;

SingleIPValue::SingleIPValue(string _value)
{
    value = _value;
}

string SingleIPValue::get_type()
{
    return "single";
}
