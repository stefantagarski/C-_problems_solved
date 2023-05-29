#include<iostream>
#include<cstring>

using namespace std;

class Book {
protected:
    char ISBN[21];
    char title[51];
    char author[30];
    double price;
public:
    Book(const char * ISBN="",const char * title="",const char * author="",double price = 0.0) {
        strcpy(this->ISBN, ISBN);
        strcpy(this->title, title);
        strcpy(this->author, author);
        this->price = price;
    }

    Book(const Book &f) {
        strcpy(this->ISBN, f.ISBN);
        strcpy(this->title, f.title);
        strcpy(this->author, f.author);
        this->price = f.price;
    }

    bool operator>(const Book &rhs) const {
        return price > rhs.price;
    }
    virtual double bookPrice() const = 0 ;

    friend ostream &operator<<(ostream &os, const Book &book) {
        os <<book.ISBN<<": "<<book.title<<", "<<book.author<<" "<<book.bookPrice()<<endl;
        return os;
    }

    void setISBN(const char *isbn) {
        strcpy(this->ISBN,isbn);
    }
    virtual ~Book()= default;
};

class OnlineBook : public Book {
protected:
    char *url;
    int size;
public:
    OnlineBook(const char * ISBN="",const char * title="",const char * author="",double price = 0.0,const char * url = "",int size = 0) : Book(ISBN,title,author,price) {
        this-> url = new char [strlen(url)+1];
        strcpy(this->url,url);
        this->size = size;
    }
    OnlineBook(const OnlineBook &o) : Book(o){
        this-> url = new char [strlen(o.url)+1];
        strcpy(this->url,o.url);
        this->size = o.size;
    }
    OnlineBook &operator=(const OnlineBook &o){
        if(this != &o){
            strcpy(this->ISBN, o.ISBN);
            strcpy(this->title, o.title);
            strcpy(this->author, o.author);
            this->price = o.price;
            delete [] url;
            strcpy(this->url,o.url);
            this->size = o.size;
        }
        return *this;
    }
    ~OnlineBook(){
        delete [] url;
    }
    double bookPrice()const override {
        double bonus;
        if(size > 20){
            bonus  = price *1.2;
            return bonus;
        }
        return price;
    }
    friend ostream& operator<<(ostream& out, const OnlineBook& onlineBook) {
        out << static_cast<const Book&>(onlineBook);
        return out;

    }


};
class PrintBook : public Book{
private:
    double mass;
    bool zaliha;
public:
    PrintBook(const char * ISBN="",const char * title="",const char * author="",double price = 0.0,double mass=0,bool zaliha=false) : Book(ISBN,title,author,price) {
        this->mass = mass;
        this->zaliha = zaliha;
    }
    double bookPrice()const override {
        double bonus = 0;
        if(mass > 0.7) {
            bonus = price * 1.15;
            return bonus;
        }else{
        return price;
    }
    }

    friend ostream &operator<<(ostream &os, const PrintBook &book) {
        os << static_cast<const Book &>(book)<<endl;
        return os;
    }
};
void mostExpensiveBook (Book** books, int n){
    int onlineCount = 0;
    int printCount = 0;
    Book* mostExpensive = books[0];

    for (int i = 0; i < n; i++) {
        if (dynamic_cast<OnlineBook*>(books[i]) != nullptr)
            onlineCount++;
        else if (dynamic_cast<PrintBook*>(books[i]) != nullptr)
            printCount++;

        if (*books[i] > *mostExpensive)
            mostExpensive = books[i];
    }

    cout << "Total number of online books: " << onlineCount << endl;
    cout << "Total number of print books: " << printCount << endl;
    cout << "The most expensive book is:" << endl;
    cout << *mostExpensive;
}
int main(){

    char isbn[20], title[50], author[30], url[100];
    int size, tip;
    float price, weight;
    bool inStock;
    Book  **books;
    int n;

    int testCase;
    cin >> testCase;

    if (testCase == 1){
        cout << "====== Testing OnlineBook class ======" << endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i < n; i++){
            cin >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            cin >> url;
            cin >> size;
            cout << "CONSTRUCTOR" << endl;
            books[i] = new OnlineBook(isbn, title, author, price, url, size);
            cout << "OPERATOR <<" << endl;
            cout << *books[i];
        }
        cout << "OPERATOR >" << endl;
        cout << "Rezultat od sporedbata e: " << endl;
        if (*books[0] > *books[1])
            cout << *books[0];
        else
            cout << *books[1];
    }
    if (testCase == 2){
        cout << "====== Testing OnlineBook CONSTRUCTORS ======" << endl;
        cin >> isbn;
        cin.get();
        cin.getline(title, 50);
        cin.getline(author, 30);
        cin >> price;
        cin >> url;
        cin >> size;
        cout << "CONSTRUCTOR" << endl;
        OnlineBook ob1(isbn, title, author, price, url, size);
        cout << ob1 << endl;
        cout << "COPY CONSTRUCTOR" << endl;
        OnlineBook ob2(ob1);
        cin >> isbn;
        ob2.setISBN(isbn);
        cout << ob1 << endl;
        cout << ob2 << endl;
        cout << "OPERATOR =" << endl;
        ob1 = ob2;
        cin >> isbn;
        ob2.setISBN(isbn);
        cout << ob1 << endl;
        cout << ob2 << endl;
    }
    if (testCase == 3){
        cout << "====== Testing PrintBook class ======" << endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i < n; i++){
            cin >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            cin >> weight;
            cin >> inStock;
            cout << "CONSTRUCTOR" << endl;
            books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
            cout << "OPERATOR <<" << endl;
            cout << *books[i];
        }
        cout << "OPERATOR >" << endl;
        cout << "Rezultat od sporedbata e: " << endl;
        if (*books[0] > *books[1])
            cout << *books[0];
        else
            cout << *books[1];
    }
    if (testCase == 4){
        cout << "====== Testing method mostExpensiveBook() ======" << endl;
        cout<<"FINKI-Education"<<endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i<n; i++){

            cin >> tip >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            if (tip == 1) {

                cin >> url;
                cin >> size;

                books[i] = new OnlineBook(isbn, title, author, price, url, size);

            }
            else {
                cin >> weight;
                cin >> inStock;

                books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
            }
        }

        mostExpensiveBook(books, n);
    }

    for (int i = 0; i<n; i++) delete books[i];
    delete[] books;
    return 0;
}
