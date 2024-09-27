#pragma once
#ifndef IPMANAGER_HPP
#define IPMANAGER_HPP

#include "IP.hpp"
#include <vector>

class IPManager
{
    public:
        void run();

    protected:
        std::vector<IP> IPs;
};

#endif
