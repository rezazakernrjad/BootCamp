
#include"bookshop.hpp"
string title_author_test[2];

int test(int menu){
    cout << "Run UnitTest on Book Shop Project... " << endl;
    BookProj::BookShop* book_shop = nullptr;
    BookProj::Book* new_book = nullptr;
    new_book = new BookProj::Book;
    book_shop = new BookProj::BookShop;
    BookProj::PrintMenu();
    int ord{0};
    string book_file= "book_list.txt";
    int s{};
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
            book_shop->EditBook(book_shop, s);
            break;
        case 5:
            book_shop->AddBookFromList(book_shop, new_book, "book_list.txt");
            break;
        case 6:
            book_shop->~BookShop();
            break;
        default:
            menu = BookProj::PrintMenu();
    }
    return 0;
}
void BookProj::search_util(string* title_author){
    cout << "Enter the Title of the book you look for: ";
    do {getline(cin, title_author[0]);}while (title_author[0]== "");
    cout << "Enter Author of the book you look for: ";
    do { getline(cin, title_author[1]);}while (title_author[1]== "");
}
// void BookProj::search_util(string* title_author){
//     cout << "Search for title: first title_1: " << title_author_test[0]<< endl;
//     title_author[0] = title_author_test[0];
//     cout << "Search for first author_1: "<< title_author_test[1]<< endl;
//     title_author[1]== title_author_test[1];
// }

int BookProj::PrintMenu(){
    int menu{0};
    
    cout << "1. Entry of New Book " << endl;;
    cout << "2. Buy a Book" <<endl;
    cout << "3. Search a Book" <<endl;
    cout << "4. Edit Details Of a Book" <<endl;
    cout << "5. Add book from file: " <<endl;
    cout << "5. Exit" <<endl;
//    cout << "Choose an action according to the menue: ";
    return menu;
}

int main(){
    int menu{0};
    test(5);
    title_author_test[0] = "first title_1";
    title_author_test[1] = "first author_1";
    test(3);
    title_author_test[0] = " ";
    title_author_test[1] = " ";
    test(3);
    test(6);
}