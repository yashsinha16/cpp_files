#include<iostream>
#include<cstring>
using namespace std;

class Sample {
    int x;
    public:
    Sample(int p):x(p) {    //Also used for conversion,but not preferred
    }
    Sample(const Sample& ref):x(ref.x) {

    }
    void printx() const {
        std::cout << x << "\n";
    }
};
int main() {
    Sample s1(10);
    s1.printx();
    //Sample s2=15; 
    //s2.printx();  //works if single param ctor is not explicit
    
             //works if single param ctor is not explicit
    Sample s2(s1);
    s2.printx();
    Sample s3=s1;
    s3.printx();   //works if copy constructor is not explicit
};
