#include"bookshop.hpp"


//asks which book needs editing, call search to find the index of the book if exists,
// then call GetBook() to receive new attrebutes and updates the book_[i] with new info
bool BookProj::BookShop::EditBook(BookShop* book_shop, Book* found_book, const int& s){

        if (s >= 0){
            cout << "To Edit found book enter books properties..." << endl;
            book_shop->book_[s].auth = found_book->auth;
            book_shop->book_[s].title = found_book->title;
            book_shop->book_[s].publisher = found_book->publisher;
            book_shop->book_[s].price = found_book->price;
            book_shop->book_[s].no_exist = found_book->no_exist;
            return true;
        } else {
            cout << "Book not found to be edited!!" << endl;
            return false;
        }
}