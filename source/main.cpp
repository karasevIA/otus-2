#include <iostream>
#include <include/ip_base.h>

int main()
{
    ip_base ip("12.255.4.2 hello");
    std::cout << "empty " << ip.empty() << std::endl;
    std::cout << ip.string() << std::endl;
    return 0;
}
