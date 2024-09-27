#include "RangeIPValue.hpp"
#include "utils.hpp"
#include <stdexcept>

using namespace std;

RangeIPValue::RangeIPValue(string _value)
{
    if (!is_range_IP_value_valid(_value))
    {
        throw invalid_argument("invalid range IP value.");
    }
    value = _value;
}
