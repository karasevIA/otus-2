#include <iostream>
#include <include/ip_base.h>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<ip_base> ip_pool;
    try {
        for(std::string line; std::getline(std::cin, line);)
        {
            ip_base ip(line);
            if (!ip.empty()) {
                ip_pool.push_back(std::move(ip));
            }
        }
    } catch(const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::sort(ip_pool.begin(), ip_pool.end(), [](ip_base a, ip_base b){return b < a;});

    for (const auto& ip : ip_pool) {
        std::cout << ip.string() << std::endl;
    }

    for (const auto& ip : ip_pool) {
        if (ip.get_byte(0) == 1) {
            std::cout << ip.string() << std::endl;        
        }
    }

    for (const auto& ip : ip_pool) {
        if (ip.get_byte(0) == 46 && ip.get_byte(2) == 70) {
            std::cout << ip.string() << std::endl;        
        }
    }

    for (const auto& ip : ip_pool) {
        for (int i = 0; i < ip.byte_count; ++i) {
            if (ip.get_byte(i) == 46) {
                std::cout << ip.string() << std::endl;        
                break;
            }
        }
    }
    
    return 0;
}
