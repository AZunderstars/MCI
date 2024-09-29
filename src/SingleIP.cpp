#include "SingleIP.hpp"

using namespace std;

SingleIP::SingleIP(string _value)
{
    value = _value;
}

string SingleIP::get_type()
{
    return "single";
}
