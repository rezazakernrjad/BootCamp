#include<string>
#include<iostream>
#include <fstream>
using namespace std;

namespace BookProj {
    struct Book {
        string title;
        string auth;
        string publisher;
//        string book_id;
//        int year_of_pub;
        int price;
        int no_exist; //how many of each book exist in store
    };

    class BookShop {
            Book* book_ = nullptr;
            int number_of_titles_; // how many titles are in the shop

        public:
            string title_author[2];
            bool GetBook(Book*);
            void AddBook(Book*);
            bool AddBookFromList(BookShop*,Book*, string);
            int SearchBook(BookShop*);
            bool EditBook(BookShop*, int&);
            bool BuyBook(BookShop*, int&, int&);
            void PrintBook(BookShop*, int);
            ~BookShop(){
                delete [] book_;
                cout << "freed borrowed heep" << endl;
            }
            void ListBooksInFile(Book*);
    };
    int PrintMenu();
    void search_util(string* title_author);
} //namespace BookProj