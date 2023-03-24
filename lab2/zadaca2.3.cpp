#include<iostream>
#include<cstring>

using namespace std;

class Book{
private:
    char name[100];
    char author[100];
    char lastName[100];
    char ISBN[100];
    int year;
public:
    Book(){}
    Book(char *n, char*a, char *isbn, char *l, int y){
        strcpy(name,n);
        strcpy(author,a);
        strcpy(lastName,l);
        strcpy(ISBN,isbn);
        year = y;
    }
    ~Book(){}

    void setBookName(char b[100]){
        strcpy(name,b);
    }
    char *getBookName(){
        return name;
    }
    void setAuthorName(char a[100]){
        strcpy(author,a);
    }
    char *getAuthorName(){
        return author;
    }
    void setAuthorSurname(char s[100]){
        strcpy(lastName,s);
    }
    char *getAuthorSurname(){
        return lastName;
    }
    void setISBN (char _isbn[100]){
        strcpy(ISBN,_isbn);
    }
    char *getISBN(){
        return ISBN;
    }
    void setYear(int yy){
        year = yy;
    }
    int getYear(){
        return year;
    }
    void display(){
        cout<<name<<","<<author<<" "<<ISBN<<","<<lastName<<endl;
    }
    void print(){
        cout<<name<<", "<<author<<" "<<ISBN<<", "<<lastName<<endl;
    }
};

void booksByOrder(Book *books,int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-1-i; ++j) {
            if(books[j].getYear() > books[j+1].getYear() ){
                Book temp = books[j];
                books[j] = books[j+1];
                books[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        books[i].print();
    }
}
//DO NOT CHANGE THE MAIN FUNCTION
int main()
{
    int m, n;
    cin>>m>>n;
    if(m==0)
    {
        cout<<"---Testing constructor with arguments and display()---"<<"\n";
        char name[100]={'H', 'a', 'm', 'l', 'e', 't'};
        char aN[100]={'W', 'i', 'l', 'l', 'i', 'a', 'm'};
        char aS[100]={'S', 'h', 'a', 'k', 'e', 's', 'p', 'e', 'a', 'r', 'e'};
        char isbn[100]={'I', 'S', 'B', 'N', '1', '2', '3', '4'};
        Book b=Book(name, aN, aS, isbn, 1847);
        b.display();
    }
    else if(m==1)
    {
        cout<<"---Testing get and set methods---"<<"\n";
        char name[100]={'H', 'a', 'm', 'l', 'e', 't'};
        char aN[100]={'W', 'i', 'l', 'l', 'i', 'a', 'm'};
        char aS[100]={'S', 'h', 'a', 'k', 'e', 's', 'p', 'e', 'a', 'r', 'e'};
        char isbn[100]={'I', 'S', 'B', 'N', '1', '2', '3', '4'};
        Book b;
        b.setYear(1847);
        b.setISBN(isbn);
        b.setAuthorSurname(aS);
        b.setAuthorName(aN);
        b.setBookName(name);
        cout<<"Name: "<<b.getBookName()<<"\n";
        cout<<"Author: "<<b.getAuthorName()<<" "<<b.getAuthorSurname()<<"\n";
        cout<<"ISBN: "<<b.getISBN()<<"\n";
        cout<<"Year: "<<b.getYear()<<"\n";
    }
    else if(m==2)
    {
        Book books[100];
        for(int i=0; i<n; i++)
        {
            char name[100], aN[100], aS[100], isbn[100];
            int year;
            cin>>name;
            cin>>aN;
            cin>>aS;
            cin>>isbn;
            cin>>year;
            books[i]=Book(name, aN, aS, isbn, year);
        }
       cout<<"---Testing order function---"<<"\n";
        booksByOrder(books, n);
    }
    return 0;
}