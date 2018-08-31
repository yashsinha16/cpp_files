class A { 
 protected:
  int m_len;
 public:
  A(int len):m_len(len) { }
  virtual ~A(){}
  virtual void fill() { }
  virtual void print() { }
};
class B:public A {
  int *m_buf;
 public:
  B(int len):A(len) {
    m_buf=new int[m_len];
  }
  ~B() {
    delete[] m_buf;
  } 
  virtual void fill() { }
  virtual void print() { }
};
int main() {
  A* ptr=new B(10);//A
  ptr->fill();
  ptr->print();
  delete ptr;
}
 
