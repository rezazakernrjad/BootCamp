



#include"bookshop.hpp"

void BookProj::BookShop::AddBook(Book* new_book){
    BookProj::Book* appended_book_array = new Book[number_of_titles_ + 1];
    for (unsigned k{}; k < number_of_titles_; ++k ){
        appended_book_array[k] = book_[k];
    }
    appended_book_array[number_of_titles_].title = new_book->title;
    appended_book_array[number_of_titles_].auth = new_book->auth;
    appended_book_array[number_of_titles_].book_id = new_book->book_id;
    appended_book_array[number_of_titles_].no_exist = new_book->no_exist;
    appended_book_array[number_of_titles_].price = new_book->price;
    appended_book_array[number_of_titles_].publisher = new_book->publisher;
    appended_book_array[number_of_titles_].year_of_pub = new_book->year_of_pub;
    delete [] book_;
    book_ = appended_book_array;
    number_of_titles_++; // NOTE THIS
}
void BookProj::BookShop::PrintBook(BookShop* book_shop, int the_book){
        cout << "******************" << endl;
        cout << "title book : " << book_shop->book_[the_book].title << endl;
        cout << "author book : " << book_shop->book_[the_book].auth << endl;
        cout << "book id book : " << book_shop->book_[the_book].book_id << endl;
        cout << "publisher : " << book_shop->book_[the_book].publisher << endl;
        cout << "year book : " << book_shop->book_[the_book].year_of_pub << endl;
        cout << "price book : " << book_shop->book_[the_book].price << endl;
        cout << "number of copies : "  << book_shop->book_[the_book].no_exist << endl;
        cout << "******************" << endl;
}
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
    cout << "Enter Book Id: ";
    getline(cin, book_attr->book_id);
    cout << "Enter Publisher: ";
    getline(cin, book_attr->publisher);
    cout << "Enter Year of Publish: ";
    cin >> book_attr->year_of_pub;
    cout << "Enter Price of the book: ";
    cin >> book_attr->price;
    cout << "Enter number of copies: ";
    cin >> book_attr->no_exist;

    return true;
    }
int BookProj::BookShop::SearchBook(BookShop* book_shop){
//    system("clear");
    cout << "Enter the Title of the book you look for: ";
    string title{};
    string author{};
    do {getline(cin, title);}while (title== "");
    cout << "Enter Author of the book you look for: ";
    do { getline(cin, author);}while (author== "");
    for (int s{}; s < book_shop->number_of_titles_; s++){
        if (book_shop->book_[s].title == title){
            if (book_shop->book_[s].auth == author){
                cout << "The Book is found successfully: " << endl;
                book_shop->PrintBook(book_shop, s);
                return s;
            }
        }
    }
    cout << "The book not found in book store data base!!"<< endl;
    return -1;
}
bool BookProj::BookShop::BuyBook(BookShop* book_shop){
         int s{};
        BookProj::Book* found_book = nullptr;
        found_book = new BookProj::Book;
        s = book_shop->SearchBook(book_shop);
        if (s >= 0){
            int ordered_number{};
            int to_pay{};
            cout << "Enter number of books to buy: ";
            cin >> ordered_number;
            book_shop->book_[s].no_exist -= ordered_number;
            book_shop->PrintBook(book_shop, s);
            cout << "Amount: $. " << book_shop->book_[s].price * ordered_number << endl;
            cout << "Book bought successfully!" << endl;
            return true;
        } else {
            cout << "Book not found to be edited!!" << endl;
            return false;
        }
}
bool BookProj::BookShop::EditBook(BookShop* book_shop){
        int s{};
        BookProj::Book* found_book = nullptr;
        found_book = new BookProj::Book;
        s = book_shop->SearchBook(book_shop);
        if (s >= 0){
            cout << "To Edit found book enter books properties..." << endl;
            book_shop->GetBook(found_book);
            book_shop->book_[s].auth = found_book->auth;
            book_shop->book_[s].title = found_book->title;
            book_shop->book_[s].book_id = found_book->book_id;
            book_shop->book_[s].publisher = found_book->publisher;
            book_shop->book_[s].price = found_book->price;
            book_shop->book_[s].year_of_pub = found_book->year_of_pub;
            book_shop->book_[s].no_exist = found_book->no_exist;
            book_shop->PrintBook(book_shop, s);
            return true;
        } else {
            cout << "Book not found to be edited!!" << endl;
            return false;
        }
}
int BookProj::PrintMenu(){
    int menu{0};
    
    cout << "1. Entry of New Book " << endl;;
    cout << "2. Buy a Book" <<endl;
    cout << "3. Search a Book" <<endl;
    cout << "4.Edit Details Of a Book" <<endl;
    cout << "5. Exit" <<endl;
    cout << "Choose an action according to the menue: ";
    do {cin >> menu;
        if (menu <= 0 || menu > 5){
            cout << "Enter according the menue...";
        }
    } while (menu <= 0 || menu > 5);
    return menu;
}
int main(){
    BookProj::BookShop* book_shop = nullptr;
    BookProj::Book* new_book = nullptr;
    new_book = new BookProj::Book;
    book_shop = new BookProj::BookShop;
    int menu = BookProj::PrintMenu();
    do {
        switch (menu) {
            case 1:
                cout << "Enter New book to the shop " << endl;
                if (book_shop->GetBook(new_book))
                    {book_shop->AddBook(new_book);}
                break;
            case 2:
                book_shop->BuyBook(book_shop);
                break;   
            case 3:
                book_shop->SearchBook(book_shop);
                break;
            case 4:
                book_shop->EditBook(book_shop);
                break;
            case 5:
                book_shop->~BookShop();
                break;
            default:
                menu = BookProj::PrintMenu();
        }
        menu = BookProj::PrintMenu();
    } while (menu != 5);
}
