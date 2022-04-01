#include<string>
#include<iostream>
using namespace std;

namespace BookProj {
    struct Book {
        string title;
        string auth;
        string publisher;
        string book_id;
        int year_of_pub;
        int price;
        int no_exist; //how many of each book exist in store
    };

    class BookShop {
            Book* book_ = nullptr;
            int ordered_number_{0}; // how many books of a title been ordered
            int number_of_titles_{0}; // how many titles are in the shop

        public:
            void GetBook(Book*);
            void AddBook(BookShop*, Book*);
            void AddBookFromList(string*);
            void SearchBook(BookShop*);
            bool EditBook(BookShop*);
            bool BuyBook(BookShop*);
            void PrintBook(BookShop*, int);
            ~BookShop();
    };
} //namespace BookProj