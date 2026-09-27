#include"gtest/gtest.h"
#include<vector>
#include<tuple>
#include"utilite.h"
#include"spliter.h"
#include<algorithm>

TEST(testsplit,splitstring){
    auto parts = split("1.2.3.4",'.');
    ASSERT_EQ(parts.size(),4u);
    EXPECT_EQ(parts[0],"1");
    EXPECT_EQ(parts[1],"2");
    EXPECT_EQ(parts[2],"3");
    EXPECT_EQ(parts[3],"4");
}

TEST(FilterTest, First46And70) {
    std::vector<ip_tuple> ips = {
        {46, 70, 1, 1},
        {46, 71, 1, 1},
        {46, 70, 200, 200},
        {1, 46, 70, 1}
    };
    std::vector<ip_tuple> filtered;
    for (const auto& ip : ips) {
        if (std::get<0>(ip) == 46 && std::get<1>(ip) == 70)
            filtered.push_back(ip);
    }
    EXPECT_EQ(filtered.size(), 2u);
}

TEST(FilterTest, AnyByteEquals46) {
    std::vector<ip_tuple> ips = {
        {186, 204, 34, 46},
        {186, 46, 222, 194},
        {39, 46, 86, 85},
        {5, 189, 203, 46},
        {1, 2, 3, 4}
    };
    std::vector<ip_tuple> filtered;
    for (const auto& ip : ips) {
        if (std::get<0>(ip) == 46 || std::get<1>(ip) == 46 ||
            std::get<2>(ip) == 46 || std::get<3>(ip) == 46)
            filtered.push_back(ip);
    }
    EXPECT_EQ(filtered.size(), 4u);
}