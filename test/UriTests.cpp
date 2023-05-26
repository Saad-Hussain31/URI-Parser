#include <gtest/gtest.h>
#include <../include/uri.hpp>


TEST(UriTests, ParseFromStringUrl) {
    Uri::Uri uri;
    ASSERT_TRUE(uri.parseFromString("http://www.example.com/foo/bar"));
    ASSERT_EQ("http", uri.getScheme());
    ASSERT_EQ("www.example.com", uri.getHost());
    ASSERT_EQ(
        (std::vector< std::string >{
            "",
            "foo",
            "bar",
        }),
        uri.getPath()
    );
}

TEST(UriTests, ParseFromStringUrnDefaultPathDelimiter){
    Uri::Uri uri;
    uri.setPathDelimiter(":");
    ASSERT_TRUE(uri.parseFromString("urn:book:fantasy:Hobbit"));
    ASSERT_EQ("urn", uri.getScheme());
    ASSERT_EQ("", uri.getHost());
    ASSERT_EQ((std::vector<std::string> {"book","fantasy","Hobbit",}), uri.getPath());
}

TEST(UriTests, ParseFromStringUrnMultiCharacterPathDelimiter) {
    Uri::Uri uri;
    uri.setPathDelimiter("/-");
    ASSERT_TRUE(uri.parseFromString("urn:bo-/ok/-fant/asy/-Hob-bit"));
    ASSERT_EQ("urn", uri.getScheme());
    ASSERT_EQ("", uri.getHost());
    ASSERT_EQ((std::vector<std::string> {"bo-/ok","fant/asy","Hob-bit",}), uri.getPath());
}


// "" -> []
// "/" -> [""]
// "/foo" -> ["", "foo"]
// "foo/" -> ["foo", ""]

TEST(UriTests, ParseFromStringPathCornerCases) {
    struct TestVectors {
        std::string pathIn;
        std::vector<std::string> pathOut;
    };

    const std::vector<TestVectors> testVectors {
        {"", {}},
        {"/",{""}},
        {"/foo", {"","foo"}},
        {"foo/", {"foo", ""}}
    };
    
    for(const auto& testVector : testVectors) {
        Uri::Uri uri;
        ASSERT_TRUE(uri.parseFromString(testVector.pathIn));
        ASSERT_EQ(testVector.pathOut, uri.getPath());
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}