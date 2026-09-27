#include <iostream>
#include"utilite.h"
#include"spliter.h"

int main(int, char**){
    try
    {
        std::vector<ip_tuple> ip_pool;

        for (std::string line; std::getline(std::cin, line);)
        {
            auto parts = split(line,'\t');
            if(parts.empty()) continue;

            auto bytes = split(parts[0],'.');
            if (bytes.size() == 4)
            {
                auto ip = std::make_tuple(
                std::stoi(bytes[0]),
                std::stoi(bytes[1]),
                std::stoi(bytes[2]),
                std::stoi(bytes[3]));
                ip_pool.push_back(ip);
            }
        }
        work_and_print_ip(ip_pool);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }   
}