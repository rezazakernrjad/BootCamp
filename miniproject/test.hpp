
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "bookshop.hpp"


class TestBokShop : public ::testing::Test
{
    public:
        TestBokShop() = default;
        void SetUp() override;
        void TearDown() override;
        BookProj::BookShop* bookshop_ = nullptr;
        BookProj::Book* book_ = nullptr;
        BookProj::Book book;
        string* title_author;
};