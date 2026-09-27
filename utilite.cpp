#include<iostream>
#include<vector>
#include<tuple>
#include"utilite.h"
#include<algorithm>
void work_and_print_ip(std::vector<ip_tuple> ip_pool){

    std::sort(ip_pool.rbegin(), ip_pool.rend());

    auto print_ip = [](const ip_tuple& ip){
        std::cout << std::get<0>(ip)<<"."
                  << std::get<1>(ip)<<"."
                  << std::get<2>(ip)<<"."
                  << std::get<3>(ip)<<"\n";
    };

    for (auto const& ip: ip_pool)
    {
        print_ip(ip);
    }

    for (auto const &ip : ip_pool)
    {
        if (std::get<0>(ip) == 1)
        {
            print_ip(ip);
        }
    }

    for (auto const& ip: ip_pool)
    {
        if (std::get<0>(ip) == 46 && std::get<1>(ip) == 70)
        {
            print_ip(ip);
        }
        
    }

    for (auto const& ip: ip_pool)
    {
        if (std::get<0>(ip) == 46 || std::get<1>(ip) == 46 || std::get<2>(ip) == 46 || std::get<3>(ip) == 46 )
        {
            print_ip(ip);
        }
        
    }
}