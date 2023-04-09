#include <iostream>
using namespace std;
int uspesni = 0, neuspesni = 0;
class List {
private:
    int *numbers;
    int count;

public:

    explicit List(const int *numbers= nullptr, int count=0) {
       this-> numbers = new int[count];
        for (int i = 0; i < count; i++) {
            this->numbers[i] = numbers[i];
        }
        this->count = count;
    }


    List(const List& other) {
        numbers = new int[other.count];
        for (int i = 0; i < other.count; i++)
            numbers[i] = other.numbers[i];
        count = other.count;
    }


    ~List() {
        delete[] numbers;
    }
    List& operator=(const List& other) {
        if (this != &other) {
            delete[] numbers;
            numbers = new int[other.count];
            for (int i = 0; i < other.count; i++)
                numbers[i] = other.numbers[i];
            count = other.count;
        }
        return *this;
    }

    int sum() {
        int s = 0;
        for (int i = 0; i < count; i++)
            s += numbers[i];
        return s;
    }


    double average() {
        if (count == 0) {
            return 0;
        }
        int s = sum();
        return (double) s / count;
    }
    void pecati() {
        int s = sum();
        double avg = average();
        cout << "List info: " << count<<": ";
        for (int i = 0; i < count; i++)
            cout << numbers[i] << " ";
        cout << "sum: " << s << " average: " << avg << endl;


    }

    int getNumElements() const{
        return count;
    }
};
class ListContainer {
private:
    List *lists;
    int numElements;
    int attempts;
public:

    explicit ListContainer(int numElements = 0, int attempts = 0) {
        lists = nullptr;
        this->numElements = numElements;
        this->attempts = attempts;
    }


    ListContainer(const ListContainer &other) {
        lists = new List[other.numElements];
        for (int i = 0; i < other.numElements; i++)
            lists[i] = other.lists[i];
        numElements = other.numElements;
        attempts = other.attempts;
    }


    ~ListContainer() {
        delete[] lists;
    }

    ListContainer &operator=(const ListContainer &other) {
        if (this != &other) {
            delete[] lists;
            lists = new List[other.numElements];
            for (int i = 0; i < other.numElements; i++)
                lists[i] = other.lists[i];
            numElements = other.numElements;
            attempts = other.attempts;
        }
        return *this;
    }
    void addNewList(List l){
            int flag = 1;
        for (int i = 0; i < numElements; ++i) {
            if(lists[i].sum() == l.sum()){
                flag = 0;
                neuspesni++;
                break;
            }
        }

        if(flag == 1){
            uspesni++;
            List *newlist = new List[numElements + 1];
            for (int i = 0; i < numElements; ++i) {
                newlist[i] = lists[i];
            }
            newlist[numElements] = l;
            delete [] lists;
            numElements++;
            lists = newlist;

        }
    }


    int sum() {
        int result = 0;
        for (int i = 0; i < numElements; i++) {
            result += lists[i].sum();
        }
        return result;
    }
    double average() const {
        int totalCount = 0;
        double totalAvg = 0.0;
        for (int i = 0; i < numElements; i++) {
            totalCount += lists[i].getNumElements();
            totalAvg += lists[i].average() * lists[i].getNumElements();
        }
        return totalAvg / totalCount;
    }
    void print() {
        if (numElements == 0) {
            cout << "The list is empty" <<endl;
        }
        else {
            int totalSum = sum();
            double totalAvg = average();
            for (int i = 0; i < numElements; i++) {
                cout << "List number: " << i + 1 << " ";
                lists[i].pecati();
            }
            cout << "Sum: " << totalSum << " Average: " << totalAvg << endl;
            cout<<"Successful attempts: "<<uspesni<<" Failed attempts: "<<neuspesni<<endl;
        }
    }


};
int main() {

    ListContainer lc;
    int N;
    cin>>N;

    for (int i=0;i<N;i++) {
        int n;
        int niza[100];

        cin>>n;

        for (int j=0;j<n;j++){
            cin>>niza[j];

        }

        List l=List(niza,n);

        lc.addNewList(l);
    }


    int testCase;
    cin>>testCase;

    if (testCase==1) {
        cout<<"Test case for operator ="<<endl;
        ListContainer lc1;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1=lc;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1.sum();
        lc1.average();

    }
    else {
        lc.print();
    }

}
