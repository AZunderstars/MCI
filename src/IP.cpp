#include "IP.hpp"
#include "SingleIPValue.hpp"

using namespace std;

IP::IP(string value)
{
    try
    {
        SingleIPValue(value);
    }
    catch (exception)
    {
    }
}
