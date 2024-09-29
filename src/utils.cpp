#include "utils.hpp"
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> parse_string_by_delimiter(string str, char delimiter)
{
    istringstream stream(str);
    vector<string> result;
    string substring;
    while (getline(stream, substring, delimiter))
    {
        result.push_back(substring);
    }
    return result;
}

bool is_IP_section_number_valid(int IP_sectioon)
{
    return IP_sectioon >= 0 and IP_sectioon <= 255;
}

bool does_string_have_char(string str, char c)
{
    return str.find(c) != string::npos;
}

bool is_single_ip_value_valid(string value)
{
    if (does_string_have_char(value, '/') or does_string_have_char(value, '-'))
    {
        return false;
    }
    vector<string> IP_sections = parse_string_by_delimiter(value, '.');
    for (string IP_section : IP_sections)
    {
        if (!is_IP_section_number_valid(stoi(IP_section)))
        {
            return false;
        }
    }
    return true;
}

bool is_mask_valid(int mask)
{
    return mask >= 0 and mask <= 32;
}

bool is_subnet_ip_value_valid(string value)
{
    if (!does_string_have_char(value, '/'))
    {
        return false;
    }
    string subnet, mask;
    vector<string> parsed_value_by_slash = parse_string_by_delimiter(value, '/');
    subnet = parsed_value_by_slash[0];
    mask = parsed_value_by_slash[1];
    return is_single_ip_value_valid(subnet) and is_mask_valid(stoi(mask));
}

bool is_IP_range_valid(string range_start, string range_end)
{
    vector<string> range_start_sections = parse_string_by_delimiter(range_start, '.');
    vector<string> range_end_sections = parse_string_by_delimiter(range_end, '.');
    for (int i = 0; i < 4; i++)
    {
        if (stoi(range_start_sections[i]) > stoi(range_end_sections[i]))
        {
            return false;
        }
    }
    return true;
}

bool is_range_ip_value_valid(string value)
{
    if (!does_string_have_char(value, '-') or count(value.begin(), value.end(), '.') < 6)
    {
        return false;
    }
    string range_start, range_end;
    vector<string> parsed_value_by_dash = parse_string_by_delimiter(value, '-');
    range_start = parsed_value_by_dash[0];
    range_end = parsed_value_by_dash[1];
    return is_single_ip_value_valid(range_start) and is_single_ip_value_valid(range_end) and is_IP_range_valid(range_start, range_end);
}
