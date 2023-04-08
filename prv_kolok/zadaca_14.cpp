#include<iostream>
#include<cstring>

using namespace std;
enum Extension {
    pdf,txt,exe
};

class File{
private:
    char *fileName;
    Extension exstension;
    char *ownerName;
    int capacity;
public:
    File(){
        fileName = NULL;
        ownerName = NULL;
        capacity = 0;
        exstension = txt;
    }
    File(const char*fileName, const char *ownerName, int capacity, Extension exstension){
        this->fileName = new char [strlen(fileName)+1];
        strcpy(this->fileName,fileName);
        this->exstension = exstension;
        this->ownerName = new char[strlen(ownerName)+1];
        strcpy(this->ownerName,ownerName);
        this->capacity = capacity;
    }
    File(const File &f){
        this->fileName = new char [strlen(f.fileName)+1];
        strcpy(this->fileName,f.fileName);
        this->exstension = f.exstension;
        this->ownerName = new char[strlen(f.ownerName)+1];
        strcpy(this->ownerName,f.ownerName);
        this->capacity = f.capacity;
    }
    ~File(){
        delete [] fileName;
        delete [] ownerName;
    }
    File &operator=(const File &f){
        if(this != &f){
            delete [] fileName;
            delete[]ownerName;
            this->fileName = new char [strlen(f.fileName)+1];
            strcpy(this->fileName,f.fileName);
            this->exstension = f.exstension;
            this->ownerName = new char[strlen(f.ownerName)+1];
            strcpy(this->ownerName,f.ownerName);
            this->capacity = f.capacity;
        }
        return *this;
    }
    void print(){
        char *type="";
        if(exstension == 0){
            type="pdf";
        }
        if(exstension == 1){
            type="txt";
        }
        if(exstension == 2){
            type="exe";
        }

        cout<<"File name: "<<fileName<<"."<<type<<endl;
        cout<<"File owner: "<<ownerName<<endl;
        cout<<"File size: "<<capacity<<endl;
    }
    bool equals (const File &that){
        return (strcmp(fileName,that.fileName) == 0 && (exstension == that.exstension)
                && (strcmp(ownerName,that.ownerName) == 0) == 1);
    }
    bool equalsType(const File &that){
        return ((strcmp(fileName,that.fileName) == 0) && (exstension == that.exstension) ==1);
    }
};

class Folder{
private:
    char *nameDirectory;
    int numberofFolders;
    File *niza;
public:
    Folder(const char* name){
        this->nameDirectory = new char[strlen(name)+1];
        strcpy(this->nameDirectory,name);
        this-> numberofFolders = 0;
        this-> niza = nullptr;
    }
    Folder(const Folder &f){
        this->nameDirectory=new char[strlen(f.nameDirectory)+1];
        strcpy(this->nameDirectory,f.nameDirectory);
        this-> numberofFolders = f.numberofFolders;
        niza = new File[f.numberofFolders];
        for (int i = 0; i < f.numberofFolders; ++i) {
            niza[i] = f.niza[i];
        }
    }
    Folder &operator=(const Folder &f){
        if(this!=&f){
            delete[]nameDirectory;
            delete[]niza;
            this->nameDirectory=new char[strlen(f.nameDirectory)+1];
            strcpy(this->nameDirectory,f.nameDirectory);
            this-> numberofFolders = f.numberofFolders;
            niza = new File[f.numberofFolders];
            for (int i = 0; i < f.numberofFolders; ++i) {
                niza[i]=f.niza[i];
            }
        }
        return *this;
    }
    ~Folder(){
        delete [] nameDirectory;
        delete [] niza;
    }
    void print(){
        cout<<"Folder name: "<<nameDirectory<<endl;
        for (int i = 0; i < numberofFolders; ++i) {
            niza[i].print();
        }
    }
    void remove(const File &file){
        for (int i = 0; i < numberofFolders; i++) {
            if (niza[i].equals(file)) {
                for (int j = i; j < numberofFolders - 1; j++) {
                    niza[j] = niza[j + 1];
                }
                numberofFolders--;
                break;
            }
        }
    }
    void add(const File &file){
        File *tmp = new File[numberofFolders+1];
        for (int i = 0; i < numberofFolders; ++i) {
            tmp[i] = niza[i];
        }
        tmp[numberofFolders++] = file;
        delete [] niza;
        niza = tmp;
    }
};

int main() {
    char fileName[20];
    char fileOwner[20];
    int ext;
    int fileSize;

    int testCase;
    cin >> testCase;
    if (testCase == 1) {
        cout << "======= FILE CONSTRUCTORS AND = OPERATOR =======" << endl;
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File created = File(fileName, fileOwner, fileSize, (Extension) ext);
        File copied = File(created);
        File assigned = created;

        cout << "======= CREATED =======" << endl;
        created.print();
        cout << endl;
        cout << "======= COPIED =======" << endl;
        copied.print();
        cout << endl;
        cout << "======= ASSIGNED =======" << endl;
        assigned.print();
    }
    else if (testCase == 2) {
        cout << "======= FILE EQUALS & EQUALS TYPE =======" << endl;
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File first(fileName, fileOwner, fileSize, (Extension) ext);
        first.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File second(fileName, fileOwner, fileSize, (Extension) ext);
        second.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File third(fileName, fileOwner, fileSize, (Extension) ext);
        third.print();

        bool equals = first.equals(second);
        cout << "FIRST EQUALS SECOND: ";
        if (equals)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        equals = first.equals(third);
        cout << "FIRST EQUALS THIRD: ";
        if (equals)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        bool equalsType = first.equalsType(second);
        cout << "FIRST EQUALS TYPE SECOND: ";
        if (equalsType)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        equalsType = second.equals(third);
        cout << "SECOND EQUALS TYPE THIRD: ";
        if (equalsType)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

    }
    else if (testCase == 3) {
        cout << "======= FOLDER CONSTRUCTOR =======" << endl;
        cin >> fileName;
        Folder folder(fileName);
        folder.print();

    }
    else if (testCase == 4) {
        cout << "======= ADD FILE IN FOLDER =======" << endl;
        char name[20];
        cin >> name;
        Folder folder(name);

        int iter;
        cin >> iter;

        while (iter > 0) {
            cin >> fileName;
            cin >> fileOwner;
            cin >> fileSize;
            cin >> ext;

            File file(fileName, fileOwner, fileSize, (Extension) ext);
            folder.add(file);
            iter--;
        }
        folder.print();
    }
    else {
        cout << "======= REMOVE FILE FROM FOLDER =======" << endl;
        char name[20];
        cin >> name;
        Folder folder(name);

        int iter;
        cin >> iter;

        while (iter > 0) {
            cin >> fileName;
            cin >> fileOwner;
            cin >> fileSize;
            cin >> ext;

            File file(fileName, fileOwner, fileSize, (Extension) ext);
            folder.add(file);
            iter--;
        }
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File file(fileName, fileOwner, fileSize, (Extension) ext);
        folder.remove(file);
        folder.print();
    }
    return 0;
}
