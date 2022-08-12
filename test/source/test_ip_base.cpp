#include <gtest/gtest.h>
#include <include/ip_base.h>
#include <string>

using namespace std::literals::string_literals;

TEST(TestConstructor, Success) {
    // arrange & act
    ip_base ip1("0.0.0.0"s);
    ip_base ip2("1.1.1.1"s);
    ip_base ip3("255.255.255.255"s);
    ip_base ip4("1.1.1.1 blabla"s);
    ip_base ip5("1.1.1.1blabla"s);
    ip_base ip6("1.1.1.1.1"s);
    
    // assert
    EXPECT_FALSE(ip1.empty());
    EXPECT_FALSE(ip2.empty());
    EXPECT_FALSE(ip3.empty());
    EXPECT_FALSE(ip4.empty());
    EXPECT_FALSE(ip5.empty());
    EXPECT_FALSE(ip6.empty());
    EXPECT_EQ(ip1.string(), "0.0.0.0"s);
    EXPECT_EQ(ip2.string(), "1.1.1.1"s);
    EXPECT_EQ(ip3.string(), "255.255.255.255"s);
    EXPECT_EQ(ip4.string(), "1.1.1.1"s);
    EXPECT_EQ(ip5.string(), "1.1.1.1"s);
    EXPECT_EQ(ip6.string(), "1.1.1.1"s);
}

TEST(TestConstructor, Errors) {
    // arrange & act
    ip_base  ip1(""s);
    ip_base  ip2("aaa"s);
    ip_base  ip3("1"s);
    ip_base  ip4("1.1.1,1"s);
    ip_base  ip5("1,1,1,1"s);
    ip_base  ip6("1..1.1"s);
    ip_base  ip7("1.1.1.-1"s);
    ip_base  ip8("1.1.1. 1"s);
    ip_base  ip9("1.1.1.1000"s);
    ip_base ip10("1.1.1.a1"s);
    ip_base ip11("1.1.1a.1"s);
    ip_base ip12("1.1.1 .1"s);
    ip_base ip13("1.1.1a1.1"s);
    ip_base ip14(".1.1.1"s);

    // assert
    EXPECT_TRUE(ip1.empty());
    EXPECT_TRUE(ip2.empty());
    EXPECT_TRUE(ip3.empty());
    EXPECT_TRUE(ip4.empty());
    EXPECT_TRUE(ip5.empty());
    EXPECT_TRUE(ip6.empty());
    EXPECT_TRUE(ip7.empty());
    EXPECT_TRUE(ip8.empty());
    EXPECT_TRUE(ip9.empty());
    EXPECT_TRUE(ip10.empty());
    EXPECT_TRUE(ip11.empty());
    EXPECT_TRUE(ip12.empty());
    EXPECT_TRUE(ip13.empty());
    EXPECT_TRUE(ip14.empty());
}

TEST(TestOperator, Check) {
    // arrange
    ip_base ip(""s);
    ip_base ip0("0.0.0.0"s);

    ip_base ip1111("1.1.1.1"s);
    ip_base ip2222("2.2.2.2"s);

    ip_base  ip2( "2.0.0.0"s);
    ip_base ip12("12.0.0.0"s);
    
    ip_base ip01("0.0.0.1"s);
    ip_base ip10("1.0.0.0"s);

    ip_base ip255("0.255.0.0"s);
    ip_base ip256("1.0.0.0"s);
    

    // act & assert
    EXPECT_TRUE(ip1111 < ip2222);
    EXPECT_TRUE(ip2 < ip12);
    EXPECT_TRUE(ip01 < ip10);
    EXPECT_TRUE(ip255 < ip256);
    EXPECT_TRUE(ip0 < ip2);
    EXPECT_TRUE(ip < ip2);
    EXPECT_TRUE(ip < ip0);
}