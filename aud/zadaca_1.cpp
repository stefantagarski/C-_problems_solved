#include <iostream>
#include<cmath>

    using namespace std;

class Triangle {
    private:
        int a,b,c;
    public:
        Triangle(int aa,int bb,int cc){ //constructor
            a = aa;
            b = bb;
            c = cc;
        }
        ~Triangle(){} //destructor

        int perimeter (){
        return a+b+c;

        }
        float area (){
            float s = perimeter()/2.0;
            return sqrt(s*(s-a)*(s-b)*(s-c));
        }
};
int main() {
    int a,b,c;
    cin>>a>>b>>c;
    Triangle l(a,b,c);
    cout<<"Perimeter is: "<<l.perimeter()<<endl;
    cout<<"Area is: "<<l.area()<<endl;

    return 0;
}
