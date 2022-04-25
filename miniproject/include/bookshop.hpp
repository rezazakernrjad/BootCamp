#ifndef BOOKSHOP_HPP
#define BOOKSHOP_HPP

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
        // to avoid of creating array of the entire class,
        // put book's related info in a struct to create array of this struct
            Book* book_ = nullptr;
            int number_of_titles_; // how many titles are in the shop

        public:
            string title_author[2];
            bool GetBook(Book*);
            void AddBook(Book*);
            bool AddBookFromList(BookShop*,Book*, string);
            int SearchBook(const BookShop*);
            bool EditBook(BookShop*, Book*, const int&);
            bool BuyBook(BookShop*, const int&, const int&);
            void PrintBook(BookShop*, const int&);
            Book* getBook() const{
                return book_;
            }
            ~BookShop(){
                delete [] book_;
                cout << "freed borrowed heep" << endl;
            }
            void ListBooksInFile(Book*);
    };
    int PrintMenu();
    void search_util(string* title_author);
} //namespace BookProj

#endif // BOOKSHOP_HPP