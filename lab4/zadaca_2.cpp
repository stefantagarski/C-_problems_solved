#include<iostream>
#include<cstring>


using namespace std;

class Student{
private:
    char * name;
    int age;
    char *major;
public:
    Student(char *name="",int age=0,char *major=""){
        this->name = new char [strlen(name)+1];
        strcpy(this->name,name);
        this->age = age;
        this->major = new char [strlen(major)+1];
        strcpy(this->major,major);
    }
    Student(const Student &s){
        this->name = new char [strlen(s.name)+1];
        strcpy(this->name,s.name);
        this->age = s.age;
        this->major = new char [strlen(s.major)+1];
        strcpy(this->major,s.major);
    }
    Student &operator=(const Student &s){
        if(this != &s){
            delete [] name;
            delete [] major;
            this->name = new char [strlen(s.name)+1];
            strcpy(this->name,s.name);
            this->age = s.age;
            this->major = new char [strlen(s.major)+1];
            strcpy(this->major,s.major);
        }
        return *this;
    }
    ~Student()
    {
        delete [] name;
        delete [] major;
    }

    char* getName() const {
        return name;
    }
    int getAge() const {
        return age;
    }
    char* getMajor() const {
        return major;
    }

};
class Classroom{
private:
    Student *students;
    int numStudents;
    int capacity;
public:
    Classroom(int numStudents=0,int capacity=0){
        this->capacity = capacity;
        this->numStudents = numStudents;
        students = new Student[capacity];
    }
    void add(Student &s) {
        if (numStudents >= capacity) {
            return;
        } else{
            students[numStudents] = s;
            numStudents++;
        }
    }
    void remove(char* name) {
        int i;
        for (i = 0; i < numStudents; i++) {
            if (strcmp(students[i].getName(),name)== 0) {
                break;
            }
        }
        if (i == numStudents) {
            return;
        }

        for (i=0; i < numStudents - 1; i++) {
            students[i] = students[i + 1];
        }
        numStudents--;
    }
    int getNumStudents() const {
        return numStudents;
    }

    Student* getStudents() const {
        return students;
    }
    void printStudents() const{
        for (int i = 0; i < numStudents; ++i) {
            cout<<students[i].getName()<<" ("<<students[i].getAge()<<
            ", "<<students[i].getMajor()<<")"<<endl;
        }
    }

};
double findMedianAge(const Classroom& classroom) {
    if (classroom.getNumStudents() == 0) {
        return 0;
    }
    Student* students = classroom.getStudents();
    int numStudents = classroom.getNumStudents();

    if (numStudents % 2 == 0) {
        return (students[numStudents / 2 - 1].getAge() + students[numStudents / 2].getAge()) / 2.0;
    } else {
        return students[numStudents / 2].getAge();
    }
}
int main() {
    int numClassrooms, numStudents;
    cin >> numClassrooms;
    Classroom classrooms[100];
    Student students[100];

    // Testing add method
    for (int i = 0; i < numClassrooms; i++) {
        cin >> numStudents;
        for (int j = 0; j < numStudents; j++) {
            char name[100], major[100];
            int age;
            cin >> name >> age >> major;
            Student student(name, age, major);
            classrooms[i].add(student);
            students[i*numStudents + j] = student;
        }
        cout<<"Classroom "<<i<<endl;
        classrooms[i].printStudents();
    }


    // Testing findMedianAge method
    int targetClassroom;
    cin >> targetClassroom;
    double medianAge = findMedianAge(classrooms[targetClassroom]);
    cout << "The median age in classroom " << targetClassroom << " is: " << medianAge << endl;
    cout<<"After removing the elements:"<<endl; /// Added 
    // Testing remove method
    cin >> numStudents;
    for (int j = 0; j < numStudents; j++) {
        char name[100];
        cin >> name;
        for (int i = 0; i < numClassrooms; i++) {
            classrooms[i].remove(name);
        }
    }
    for (int i = 0; i < numClassrooms; i++) {
        cout<<"Classroom "<<i<<endl;
        classrooms[i].printStudents();
    }

    return 0;
}
