#include "SingleIPValue.hpp"
#include "utils.hpp"
#include <stdexcept>

using namespace std;

SingleIPValue::SingleIPValue(string _value)
{
    if (!is_single_IP_value_valid(value))
    {
        throw invalid_argument("invalid single IP value.");
    }
    value = _value;
}
