#include "json.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
using namespace std;
using json = nlohmann::json;
class acc {
private:
  double a;
  double b;
  double c;
  string str_time;

public:
  acc(double x, double y, double z, string w) : a(x), b(y), c(z), str_time(w) {}
  void display() { cout << a << "\t" << b << "\t" << c << "\t" << str_time; }
};



void ReadingData(json j_complete) {
  std::vector<acc> myvector;
  int count = 0;

  for (auto entry : j_complete) {
    acc newacc(entry.value("LIGHT (lux)", 0.0l),
               entry.value("SOUND LEVEL (dB)", 0.0l),
               entry.value("LINACC_Z", 0.0l),
               entry.value("YYYY-MO-DD HH-MI-SS_SSS", ""));
    myvector.push_back(newacc);
    count += 1;
  }

  for (auto it = myvector.begin(); it != myvector.end(); it++) {
    it->display();
    cout << count << "\n";
  }
  cout << "total data points: " << count << "\n";
}

int main() {

  std::ifstream fin("data.json");
  
  json parsed_data = json::parse(fin);
  fin.unsetf(ios::skipws);
  ReadingData(parsed_data);
  return 0;
}
