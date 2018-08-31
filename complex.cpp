#include <iostream>
using namespace std;

class complex {
private:
  int real, imaginary;

public:
  complex(int r = 0, int i = 0) {
    real = r;
    imaginary = i;}

    friend ostream &operator<<(ostream &out, const complex &c);
    friend istream &operator>>(istream &in, complex &c);
  
  complex(const complex &obj) {
    real = obj.real;
    imaginary = obj.imaginary;
  }

  complex add(complex c) {
    complex add;
    add.real = real + c.real;
    add.imaginary = imaginary + c.imaginary;
    return add;
  }

  complex sub(complex c) {
    complex sub;
    sub.real = real - c.real;
    sub.imaginary = imaginary - c.imaginary;
    return sub;
  }

  complex mult(complex c) {
    complex mult;
    mult.real = real * c.real - imaginary * c.imaginary;
    mult.imaginary = real * c.imaginary + imaginary * c.real;
    return mult;
  }

  complex operator+(const complex &ref) {
    double treal = real + ref.real;
    double timag = real + ref.imaginary;
    // Complex res(treal,timag);
    // return res;
    return complex(treal, timag); // unnamed/ anonymous object
  }

  complex operator*(const complex &ref) {
    double treal = real * ref.real - imaginary * ref.imaginary;
    double timag = real * ref.imaginary + imaginary * ref.real;
    return complex(treal, timag);
  }

  void print() { cout << real << "+" << imaginary << "i" << endl; }
  int getReal() { return real; }

  int getImaginary() { return imaginary; }
};
ostream &operator<<(ostream &out, const complex &c) {
  out << c.real;
  out << "+i" << c.imaginary << endl;
  return out;
}

istream &operator>>(istream &in, complex &c) {
  cout << "Enter Real Part ";
  in >> c.real;
  cout << "Enter Imaginary Part ";
  in >> c.imaginary;
  return in;
}

int main() {
  int real1, real2, imaginary1, imaginary2;
  cout << "enter real part of first: ";
  cin >> real1;
  cout << "enter imaginary part of first number: ";
  cin >> imaginary1;
  complex obj1(real1, imaginary1);
  obj1.print();

  cout << "enter real part of second: ";
  cin >> real2;
  cout << "enter imaginary part of second number: ";
  cin >> imaginary2;
  complex obj2(real2, imaginary2);
  obj2.print();

  complex c;
  c = obj1.add(obj2);
  cout << "addition is: " << c.getReal() << " + " << c.getImaginary() << "i"
       << endl;

  complex c1(real1, imaginary1);
  complex c2(real2, imaginary2);
  complex c3;
  complex c4;
  c3 = c1 + c2;
  c4 = c1 * c2;
  c3.print();
  c4.print(); // c1.operator + (c2)

  complex c5;
  cin >> c5;
  cout << "The complex object is ";
  cout << c5;

  return 0;
}
