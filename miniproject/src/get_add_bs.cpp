



#include"bookshop.hpp"
// generall function to add new book/s from user or text file to the Book array
//with each new book the size of book_ increases.
void BookProj::BookShop::AddBook(Book* new_book){
    BookProj::Book* appended_book_array = new Book[number_of_titles_ + 1];
    for (unsigned k{}; k < number_of_titles_; ++k ){
        appended_book_array[k] = book_[k];
    }
    appended_book_array[number_of_titles_].title = new_book->title;
    appended_book_array[number_of_titles_].auth = new_book->auth;
    appended_book_array[number_of_titles_].no_exist = new_book->no_exist;
    appended_book_array[number_of_titles_].price = new_book->price;
    appended_book_array[number_of_titles_].publisher = new_book->publisher;
    delete [] book_;
    book_ = appended_book_array;
    number_of_titles_++; // NOTE THIS
}
void BookProj::BookShop::PrintBook(BookShop* book_shop, const int& the_book){
        cout << "******************" << endl;
        cout << "title book : " << book_shop->book_[the_book].title << endl;
        cout << "author book : " << book_shop->book_[the_book].auth << endl;
        cout << "publisher : " << book_shop->book_[the_book].publisher << endl;
        cout << "price book : " << book_shop->book_[the_book].price << endl;
        cout << "number of copies : "  << book_shop->book_[the_book].no_exist << endl;
        cout << "******************" << endl;
}
//receives book's attrebutes from user or text file
// checks if the entry book is already exists, if not then pass book_attr* to AddBook()
bool BookProj::BookShop::GetBook(Book* book_attr){
    cout << "Enter book title: ";
    do {getline(cin, book_attr->title);}while (book_attr->title== "");
    cout << "Enter author name: ";
    do {getline(cin, book_attr->auth);}while (book_attr->auth=="");
    for (int it=0; it<number_of_titles_; ++it){
        if (book_[it].auth == book_attr->auth &&
             book_[it].title == book_attr->title){
            cout << "This book is already found in the data base!" << endl;
            return false;
        }
    }
    cout << "Enter Publisher: ";
    getline(cin, book_attr->publisher);
    cout << "Enter Price of the book: ";
    cin >> book_attr->price;
    cout << "Enter number of copies: ";
    cin >> book_attr->no_exist;

    return true;
    }
#if 0
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
#endif
#if 0
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
#endif
#if 0
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
#endif
#if 0
// reads a list of books from a text file, looks for first word in each line
// updates book_[] according to the list.
bool BookProj::BookShop::AddBookFromList(BookShop* book_shop, Book* book_file, string book_list){
fstream newfile;
   
   newfile.open(book_list,ios::in); 
   if (newfile.is_open()){ 
      string tp;
      string catched;
      string book_attr{""};
      while(getline(newfile, tp)){
      book_attr = tp.substr(0, 7);
         if (book_attr == "title :"){
            book_file->title = tp.substr(8,40);
         } else if(book_attr == "author:") {
            book_file->auth = tp.substr(8,40);
            for (int it=0; it<number_of_titles_; ++it){
                if (book_[it].auth == book_file->auth &&
                book_[it].title == book_file->title){
                cout << "This book is already found in the data base! Check the List!" << endl;
                return false;
        }
    }
         } else if (book_attr == "publsh:"){
            book_file->publisher = tp.substr(8,40);
         } else if (book_attr == "price :"){
            book_file->price = stoi(tp.substr(8, 40));
         } else if (book_attr == "copies:"){
            book_file->no_exist = stoi(tp.substr(8, 40));
         } else{
             book_shop->AddBook(book_file);
         }
      }
      newfile.close(); //close the file object.
   }
   return true;
}
#endif
#if 0

void BookProj::search_util(string* title_author){
    cout << "Enter the Title of the book you look for: ";
    do {getline(cin, title_author[0]);}while (title_author[0]== "");
    cout << "Enter Author of the book you look for: ";
    do { getline(cin, title_author[1]);}while (title_author[1]== "");
}
int BookProj::PrintMenu(){
    int menu{0};
    
    cout << "1. Entry of New Book " << endl;;
    cout << "2. Buy a Book" <<endl;
    cout << "3. Search a Book" <<endl;
    cout << "4. Edit Details Of a Book" <<endl;
    cout << "5. Add book from file: " <<endl;
    cout << "6. Exit" <<endl;
    cout << "Choose an action according to the menue: ";
    do {cin >> menu;
        if (menu <= 0 || menu > 6){
            cout << "Enter according the menue...";
        }
    } while (menu <= 0 || menu > 6);
    return menu;
}
int main(){
    cout << "Run UnitTest on Book Shop Project... " << endl;
    BookProj::BookShop* bs= nullptr;
    BookProj::BookShop* book_shop = nullptr;
    BookProj::Book* new_book = nullptr;
    new_book = new BookProj::Book;
    book_shop = new BookProj::BookShop;
    int menu = BookProj::PrintMenu();
    int ord{0};
//    menu = 1;
    string book_file= "book_list.txt";
    int s{};
    while (menu != 6) {
        switch (menu) {
            case 1:
                cout << "Enter New book to the shop " << endl;
                if (book_shop->GetBook(new_book))
                    {book_shop->AddBook(new_book);}
                break;
            case 2:
                s = book_shop->SearchBook(book_shop);
                if (s >= 0){
                    cout << "Enter number of books to buy: ";
                    cin >> ord;
                    book_shop->BuyBook(book_shop, s, ord);
                } else {
                    cout << "Book not found to be edited!!" << endl;
                }
                break;   
            case 3:
                book_shop->SearchBook(book_shop);
                break;
            case 4:
                s = book_shop->SearchBook(book_shop);
                book_shop->GetBook(new_book);
                book_shop->EditBook(book_shop, new_book, s);
                break;
            case 5:
                book_shop->AddBookFromList(book_shop, new_book, "book_list.txt");
                break;
            default:
                menu = BookProj::PrintMenu();
        }
        menu = BookProj::PrintMenu();
    } ;//while (menu != 6);
    // case 6:
    book_shop->~BookShop();
    return 0;
}
#endif