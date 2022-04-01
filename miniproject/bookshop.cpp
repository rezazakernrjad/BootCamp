



#include"bookshop.hpp"

void BookProj::BookShop::AddBook(BookShop* book_shop, Book* new_book){
    BookProj::Book* appended_book_array = new Book[number_of_titles_ + 1];
//    copy(book_, book_ + number_of_titles_, appended_book_array);
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
    book_shop->PrintBook(book_shop, number_of_titles_);
    number_of_titles_++; // NOTE THIS
}
void BookProj::BookShop::PrintBook(BookShop* book_shop, int the_book){
        cout << "******************" << endl;
        cout << "author book : " << the_book << "  " << book_shop->book_[the_book].auth << endl;
        cout << "title book : " << the_book << "  " << book_shop->book_[the_book].title << endl;
        cout << "book id book : " << the_book<< "  " << book_shop->book_[the_book].book_id << endl;
        cout << "no_exist book : " << the_book << "  " << book_shop->book_[the_book].no_exist << endl;
        cout << "price book : " <<the_book << "  " << book_shop->book_[the_book].price << endl;
        cout << "publisher book : " << the_book<< "  " << book_shop->book_[the_book].publisher << endl;
        cout << "year book : " << the_book << "  " << book_shop->book_[the_book].year_of_pub << endl;
        cout << "******************" << endl;
}
void BookProj::BookShop::GetBook(Book* book_attr){
    cout << "Enter New book to the shop " << endl;
    cout << "Enter book title: ";
    
    do {getline(cin, book_attr->title);}while (book_attr->title== "");
    cout << "Enter author name: ";
    getline(cin, book_attr->auth);
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
    }
void BookProj::BookShop::SearchBook(BookShop* book_shop){
    system("clear");
    cout << "Enter name of the book you look for: ";
    string title{};
    string author{};
    do {getline(cin, title);}while (title== "");
    cout << "Enter Author of the book you look for: ";
    do {getline(cin, author);}while (author== "");
    for (int s{}; s < book_shop->number_of_titles_; s++){
        if (book_shop->book_[s].title == title){
            if (book_shop->book_[s].auth == author){
                cout << "The book you are looking for is: " << endl;
                book_shop->PrintBook(book_shop, s);
            }
        }
    }
    cout << "The book not found in book store data base!!"<< endl;
}
int main(){
    BookProj::BookShop* book_shop = nullptr;
    BookProj::Book* new_book = nullptr;
    new_book = new BookProj::Book;
    book_shop = new BookProj::BookShop;
    int no{0};
    do {
        book_shop->GetBook(new_book);
        book_shop->AddBook(book_shop, new_book);
        no++;
    }while (no < 3);
    book_shop->SearchBook(book_shop);
}
