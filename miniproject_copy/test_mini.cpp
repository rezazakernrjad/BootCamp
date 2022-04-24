#include "test.hpp"
#include <iostream>
using namespace std;
string title_author_test[2];
void TestBokShop::SetUp(){
    book_ = new BookProj::Book;
    bookshop_ = new BookProj::BookShop;
    bookshop_->AddBookFromList(bookshop_, book_, "../book_list.txt");
}
void TestBokShop::TearDown(){
//    bookshop_->~BookShop();
}
void BookProj::search_util(string* title_author){
    title_author[0] = title_author_test[0];
    title_author[1] = title_author_test[1];
}

TEST_F(TestBokShop, AddBookFromList){
    book = bookshop_->getBook()[0];
    EXPECT_EQ(book.auth, "a_1");
    EXPECT_EQ(book.title, "t_1");
    book = bookshop_->getBook()[1];
    EXPECT_EQ(book.auth, "a_2");
    EXPECT_EQ(book.title, "t_2");
    book = bookshop_->getBook()[6];
    EXPECT_EQ(book.auth, "a_7");
    EXPECT_EQ(book.title, "t_7");
}

TEST_F(TestBokShop, BuyBook){
    title_author_test[0] = "t_2";
    title_author_test[1] = "a_2";
    int s = bookshop_->SearchBook(bookshop_);
    bool buy_book = bookshop_->BuyBook(bookshop_, s, 10);
    EXPECT_EQ(buy_book, true); 

    book = bookshop_->getBook()[1];
    EXPECT_EQ(book.no_exist, 19990); // 20000 -10

    title_author_test[0] = "not exists";
    title_author_test[1] = "not exists";
    s = bookshop_->SearchBook(bookshop_);
    buy_book = bookshop_->BuyBook(bookshop_, s, 10);
    EXPECT_EQ(buy_book, false);

    title_author_test[0] = "t_2";
    title_author_test[1] = "a_2";
    s = bookshop_->SearchBook(bookshop_);
    buy_book = bookshop_->BuyBook(bookshop_, s, 20001);
    EXPECT_EQ(buy_book, false);
}

TEST_F(TestBokShop, BuyNotExistingBook){
    title_author_test[0] = "not exists";
    title_author_test[1] = "not exists";
    int s = bookshop_->SearchBook(bookshop_);
    bool buy_book = bookshop_->BuyBook(bookshop_, s, 10);
    EXPECT_EQ(buy_book, false);
}

// TEST_F(TestBokShop, BuyTooManyBooks){
//     title_author_test[0] = "t_2";
//     title_author_test[1] = "a_2";
//     int s = bookshop_->SearchBook(bookshop_);
//     bool buy_book = bookshop_->BuyBook(bookshop_, s, 20001);
//     EXPECT_EQ(buy_book, false);
// }


// TEST_F(TestBokShop, SearchBook){
//     title_author_test[0] = "t_1";
//     title_author_test[1] = "a_1";
//     int s = bookshop_->SearchBook(bookshop_);
//     EXPECT_EQ(s,0); // t_1, a_1 is the first book in the book_[] with index=0;
//     title_author_test[0] = "t_7";
//     title_author_test[1] = "a_7";
//     s = bookshop_->SearchBook(bookshop_);
//     EXPECT_EQ(s,6);

//     title_author_test[0] = "not exists";
//     title_author_test[1] = "not exists";
//     s = bookshop_->SearchBook(bookshop_);
//     EXPECT_EQ(s,-1);
// }
// 
// TEST_F(TestBokShop, SearchNotExistingBook){
//     title_author_test[0] = "not exists";
//     title_author_test[1] = "not exists";
//     int s = bookshop_->SearchBook(bookshop_);
//     EXPECT_EQ(s,-1);
// }

TEST_F(TestBokShop, EditBook){
    title_author_test[0] = "t_1";
    title_author_test[1] = "a_1";
    int s = bookshop_->SearchBook(bookshop_);
    EXPECT_EQ(s,0);
    book_->auth = "A_test_edit";
    book_->title = "T_test_edit";
    book_->publisher = "P_test_edit";
    book_->price = 125;
    book_->no_exist = 12000;
    bool edit_fb = bookshop_->EditBook(bookshop_, book_, s);
    EXPECT_EQ(edit_fb, true);
    book = bookshop_->getBook()[0];
    EXPECT_EQ(book.auth, "A_test_edit");
}