#pragma once
#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

bool is_single_IP_value_valid(std::string value);
bool is_subnet_IP_value_valid(std::string value);
bool is_range_IP_value_valid(std::string value);

#endif
