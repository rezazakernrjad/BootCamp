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
            int number_of_titles_{0}; // how many titles are in the shop

        public:
            bool GetBook(Book*);
            void AddBook(Book*);
            void AddBookFromList(string*);
            int SearchBook(BookShop*);
            bool EditBook(BookShop*);
            bool BuyBook(BookShop*);
            void PrintBook(BookShop*, int);
            ~BookShop(){
                delete [] book_;
                cout << "freed borrowed heep" << endl;
            }
            void ListBooksInFile(Book*);
    };
    int PrintMenu();
} //namespace BookProj