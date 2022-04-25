#include"bookshop.hpp"

//receives author and title, then call SearchBook() to see if the book exists and if yes,
// where in the book_[] is located. then asks for the number of copies to buy then calculates the total price
//if the number of buy is greater han number of copies gives a warning message.
bool BookProj::BookShop::BuyBook(BookShop* book_shop, const int& s, const int& ordered_number){
        BookProj::Book* found_book = nullptr;
        found_book = new BookProj::Book;
            bool isbought{false};
            int to_pay{};
            if (book_shop->book_[s].no_exist > 0) {
                if (ordered_number < book_shop->book_[s].no_exist){
                    book_shop->book_[s].no_exist -= ordered_number;
                    cout << "Amount: $. " << book_shop->book_[s].price * ordered_number << endl;
                    isbought = true;
                } else {
                    cout << "buying book failed, number of order is too big" << endl;
                    isbought = false;
                }
            } else {
                cout << "This book sold out!!" << endl;
                isbought = false;
            }
            return isbought;
}