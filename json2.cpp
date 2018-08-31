#include "json.hpp"


#include <iostream>
#include <sstream>
using namespace std;
using json = nlohmann::json;
json encoder;
int main() {
  auto text = R"({
     "temperature":24,
     "humidity":72,
     "pressure":560
  })";
  std::stringstream ss;
  ss << text;
  json j_complete = json::parse(ss);
  // print j_complete.at("temperature").get<int>()
  //j_complete.value("temperature", 0);

  //j_complete.value("pressure", 0);
 // print j_complete.at("humidity").get<int>()
  // print j_complete.at("pressure").get<int>()
 // std::ifstream fin("simple1.json");
 // json complete = json::parse(fin);
  cout << j_complete.at("temperature").get<int>() <<endl;
//  fin << complete.value("temperature", 0) << "\n";
  //fin.close();
  // json j_complete = json::parse(fin);
  return 0;
}
