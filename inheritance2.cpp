#include<iostream>
#include<cmath>
class Polygon
{
  int sides;
  
  
  public:
  Polygon(int x):sides(x)
  {}
    
  
 virtual double area()
  {
    std::cout << "no of sides :" << sides<< "\n";
    
  }
};
class Triangle:public Polygon
{
  double side1;
  double side2;
  double side3;
  std::string name;
  public:
  Triangle(int x,double s1,double s2,double s3,std::string n1):Polygon(x),side1(s1),side2(s2),side3(s3),name(n1)
  {
    
  }
  double area()
  {
    
    std::cout << "name1:" << "\n";
    
  }
};
class Rectangles:public Polygon
{
    double length;
    double width;
    std:: string name;
    public:
    Rectangles(int x,double l1, double w1,std::string s1):Polygon(x),length(l1),width(w1),name(s1)
    {
    }   
    double area()
  {
    
    std::cout << "name2:" << "\n";
    
  }
};
int main() {
  Polygon *ptr1=new Triangle(3,10,12,5,"triangle");
  Polygon *ptr2=new Rectangles(4,3,10,"rectangle");
  ptr1->area();
  ptr2->area();    
  
  return 0;
}
