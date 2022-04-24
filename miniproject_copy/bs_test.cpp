
#include"bookshop.hpp"
string title_author_test[2];

void BookProj::search_util(string* title_author){
    title_author[0] = title_author_test[0];
    title_author[1] = title_author_test[1];
}

int BookProj::PrintMenu(){
    int menu{0};
    return menu;
}
int TestSearchBook(BookProj::BookShop* book_shop){
    cout << '\n' <<"---test Search book---" << endl;
    int s = book_shop->SearchBook(book_shop);
    return s;
}
bool TestBuyBook(BookProj::BookShop* book_shop, int& ordered_number){
    cout << '\n' <<"---test BUYING book---" << endl;
    int s{};
    bool buy_test{false};
     cout << "Buy " << ordered_number << " books of "<< title_author_test[0] << endl;
    s = book_shop->SearchBook(book_shop);
            if (s >= 0){
                book_shop->BuyBook(book_shop, s, ordered_number);
                buy_test = true;
            } else {
                cout << "Book not found to be edited!!" << endl;
                buy_test = false;
            }
    return buy_test;
}
bool TestAddBookFromList(BookProj::BookShop* book_shop, BookProj::Book* new_book){
    cout << '\n' <<"---test Adding book from a text file---" << endl;
    bool list_fb{false};
    if (book_shop->AddBookFromList(book_shop, new_book, "../book_list.txt")){
        list_fb= true;
    } else {list_fb= false;}
    return list_fb;
}
bool TestEditBook(BookProj::BookShop* book_shop, BookProj::Book* new_book){
    cout << '\n' <<"---test EDITING book---" << endl;
    bool edit_book_fb{false};
    int s = book_shop->SearchBook(book_shop);
    new_book->auth = "A_test_edit";
    new_book->title = "T_test_edit";
    new_book->publisher = "P_test_edit";
    new_book->price = 125;
    new_book->no_exist = 12000;
    book_shop->EditBook(book_shop, new_book, s);
    book_shop->AddBook(new_book);
    // cout << "Edited book in BookShop object after editing" << endl;
    // book_shop->PrintBook(book_shop, s);
    // cout << "SEARCH FOR EDITED BOOK..." << endl;
    title_author_test[0] = "T_test_edit";
    title_author_test[1] = "A_test_edit";
    if (book_shop->SearchBook(book_shop) >= 0) {edit_book_fb= true;}
    return edit_book_fb;
}

int main(){
    int order_number{5};
    cout << "Run UnitTest on Book Shop Project... " << endl;
    BookProj::BookShop* book_shop = nullptr;
    BookProj::Book* new_book = nullptr;
    new_book = new BookProj::Book;
    book_shop = new BookProj::BookShop;
    int menu{0};
    if (TestAddBookFromList(book_shop, new_book)){
        cout << "Test Add Book From List SUCCESSFULL" << endl;
        } else {
            cout << "Test Add Book From List FAILED" << endl;
        }
    
//    test(book_shop, new_book, 5);
    title_author_test[0] = "t_1";
    title_author_test[1] = "a_1";
    if (TestSearchBook(book_shop) >=0){
        cout << "Test Book Search SUCCESSFULL" << endl;
    } else{
        cout << "Test Book Search FAILED" << endl;
    }
    if (TestBuyBook(book_shop, order_number)){
            cout << "Test Buy Book SUCCESSFUL" << endl;
        } else {
            cout << "Test Buy Book FAILED" << endl;
    }
    if (TestEditBook(book_shop, new_book)){
        cout << "TEST Edit book SUCCESSFUL" << endl;
    } else{
        cout << "TEST Edit book FAILED" << endl;
    }
    title_author_test[0] = " not existing title ";
    title_author_test[1] = " not existing author";
    if (TestBuyBook(book_shop, order_number)){
            cout << "Test Buy NOT existing Book FAILED" << endl;
        } else {
            cout << "Test Buy NOT existing Book SUCCESSFULL" << endl;
        }
     if (TestSearchBook(book_shop) >=0){
        cout << "Test SEARCH NOT existing Book FAILED" << endl;
    } else{
        cout << "Test SEARCH NOT existing Book SUCCESSFULL" << endl;
    }
    book_shop->~BookShop();
}