#include "SubnetIPValue.hpp"
#include "utils.hpp"
#include <stdexcept>

using namespace std;

SubnetIPValue::SubnetIPValue(string _value)
{
    if (!is_subnet_IP_value_valid(_value))
    {
        throw invalid_argument("invalid subnet IP value.");
    }
    value = _value;
}
