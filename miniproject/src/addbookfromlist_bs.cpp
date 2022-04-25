#include"bookshop.hpp"


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