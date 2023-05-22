#include <gtest/gtest.h>
#include <../include/uri.hpp>


TEST(UriTests, ParseFromString) {
    Uri::Uri uri;
    ASSERT_TRUE(uri.parseFromString("http://www.example.com/foo/bar"));
    ASSERT_EQ("http", uri.getScheme());
    ASSERT_EQ("www.example.com", uri.getHost());
    ASSERT_EQ((std::vector<std::string> {"","foo","bar",}), uri.getPath());
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}