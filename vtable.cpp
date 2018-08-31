class A {
 public:
  virtual void f1();
  virtual void f2();
};
class B:public A {
 public:
  virtual void f1();
  virtual void f3();
};
