#pragma once
#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>

bool is_single_IP_value_valid(std::string value);
bool is_subnet_IP_value_valid(std::string value);
bool is_range_IP_value_valid(std::string value);
std::vector<std::string> parse_string_by_delimiter(std::string str, char delimiter);

#endif
