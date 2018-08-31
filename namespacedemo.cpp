#include <iostream>
using namespace std;
namespace org {
namespace kpit {
class bangalore {
  int x;

public:
  bangalore(int p) : x(p) {}
  static void print() {
    cout << "hi FROM BANGALORE"
         << "\n";
  }
};
 // namespace kpit
namespace munich {
class bav {
public:
  static void print() {
    cout << "hi FROM MUNICH"
         << "\n";
  }
};
} // namespace munich
} 
}// namespace org
int main() {
  org::kpit::munich::bav::print();
  return 0;
}
