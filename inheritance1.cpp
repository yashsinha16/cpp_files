#include<iostream>
using namespace std;
class A
{
  int x;
  public:
  A(int p):x(p) 
  {
    x=p;
  }
  void printx()
  {
    std::cout << "A--x=" << "\n";
  }
};
class B:public A
{
  int y;
  public:
  B(int p,int q):A(p),y(q)
  {
    
  }
  void printxy()
  {
    printx();
    cout << y << "\n";
  }
};
int main() {
  B b1(10,20);
  b1.printxy();
  return 0;
}
