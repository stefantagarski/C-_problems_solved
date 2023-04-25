#include <iostream>
#include <cstring>

using namespace std;

class Book {
private:
    char *name;
    int *isbn;
    int n;
public:
    Book(const char* name = "", const int* isbn = nullptr, int n = 0) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->isbn = new int[5];
        for (int i = 0; i < 5; ++i) {
            if (isbn != nullptr) {
                this->isbn[i] = isbn[i];
            } else {
                this->isbn[i] = 0;
            }
        }
        this->n = n;
    }
    Book(const Book& b) {
        name = new char[strlen(b.name) + 1];
        strcpy(name, b.name);
        isbn = new int[b.n];
        for (int j = 0; j < b.n; j++) {
            isbn[j] = b.isbn[j];
        }
        n = b.n;
    }
    Book &operator=(const Book &b){
        if(this != &b){
            delete [] name;
            name = new char[strlen(b.name) + 1];
            strcpy(name, b.name);
            delete [] isbn;
            isbn = new int[b.n];
            for (int j = 0; j < b.n; j++) {
                isbn[j] = b.isbn[j];
            }
            n = b.n;
        }
        return  *this;
    }
    ~Book() {
        delete[] name;
        delete[] isbn;
    }

    bool operator==(const Book& other) const {
            return isbn == other.isbn;
    }

    friend ostream& operator<<(ostream& os, const Book& book)
  {
        os << "Title: " << book.name << " ISBN: [ ";
        for (int j = 0; j < 5; j++) {
            os << book.isbn[j] << " ";
        }
        os<< "]" << endl;
        return os;
    }

    int getN() const {
        return n;
    }
};
class BorrowABook {
private:
    char name[100];
    Book *niza;
    int n;
public:
     BorrowABook(const char *name) {
        n = 0;
        niza = new Book[0];
        strcpy(this->name, name);
    }
    BorrowABook(const BorrowABook &brw){
         n = brw.n;
         strcpy(name,brw.name);
         niza = new Book[n];
        for (int i = 0; i < n; ++i) {
            niza[i] = brw.niza[i];
        }
     }
     BorrowABook &operator=(const BorrowABook &brw){
         if(this != &brw) {
             n = brw.n;
             strcpy(name, brw.name);
             delete[] niza;
             niza = new Book[n];
             for (int i = 0; i < n; ++i) {
                 niza[i] = brw.niza[i];
             }
         }
             return *this;

     }
    ~BorrowABook() {
        delete[] niza;
    }

    BorrowABook &operator+=(const Book &book) {
        Book *tmp = new Book[n + 1];
        for (int i = 0; i < n; i++) {
            tmp[i] = niza[i];
        }
        tmp[n++] = book;
        delete[] niza;
        niza = tmp;
        return *this;
    }
    BorrowABook &operator -=(const Book &book) {
        int flag  = 0;
         for (int i = 0; i < n; ++i) {
            if((book == niza[i])){
                flag  = 1;
                break;
            }
        }
         if(flag == 0){
             return  *this;
         }

         Book *tmp = new Book[n - 1];
        int j = 0;
        for (int i = 0; i < n; ++i) {
                tmp[j] = niza[i];
                j++;
        }
        n--;
        delete[] niza;
        niza = tmp;
        return *this;
    }


    void printNumberOfPages(int max) const {
        cout << name << endl;
        for (int i = 0; i < n; i++) {
            if (niza[i].getN() > max)
                cout << niza[i];

        }
    }

};
int main()
{
    BorrowABook library("FINKI-Library");
    int n;
    cin>>n;

    for (int i=0;i<n;i++)
    {
        char title[100];
        int isbn[5];
        int pages;

        cin>>title;

        for (int i=0;i<5;i++)
            cin>>isbn[i];

        cin>>pages;

        Book nov=Book(title,isbn,pages);

        //adding a new book
        library+=nov;
    }

    //the book which has the same isbn as some previous one
    char title[100];
    int isbn[5];
    int pages;
    cin>>title;
    for (int i=0;i<5;i++)
        cin>>isbn[i];
    cin>>pages;

    Book greshka=Book(title,isbn,pages);

    //deleting a book
    library-=greshka;

    library.printNumberOfPages(150);

    return 0;
}