#include"bookshop.hpp"

//looks for author and titte got from user, if both matches any book in the book_[]
// returns the index of the book in book_[] if not, returns -1.
int BookProj::BookShop::SearchBook(const BookShop* book_shop){
//    system("clear");
    search_util(title_author);
    string title{title_author[0]};
    string author{title_author[1]};
    for (int s{}; s < book_shop->number_of_titles_; s++){
        if (book_shop->book_[s].title == title){
            if (book_shop->book_[s].auth == author){
                return s;
            }
        }
    }
    return -1;
}