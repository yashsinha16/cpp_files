#include "json.hpp"
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;
using json = nlohmann::json;

class Light {
private:
  int intensity;

public:
  Light(int a) : intensity(a) {}
  void display() { cout << intensity<<endl; }

  double getvalue() { 
  cout<<intensity<<endl;
  
  
  return intensity; }
};

vector<Light> ReadValues(json j_complete) {
  std::vector<Light> myvector;

  for (auto entry : j_complete) {

    myvector.push_back(Light(entry.value("LIGHT (lux)", 0)));
  }
  for (auto it = myvector.begin(); it != myvector.end(); it++) {
    it->display();
  
  return myvector;
}}

void DisplayReading(vector<double> v) {
  for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << endl;
  }
}

int main() {
  std::ifstream fin("data.json");
  json parsed_data = json::parse(fin);
  vector<Light> myvector = ReadValues(parsed_data);

  map<int, string> m;
  m[0] = "You are in Pitch Black conditions";
  m[1] = "You are in Very Dark condition";
  m[2] = "You are visiting Dark Indoors";
  m[3] = "It's Dim Indoors";
  m[4] = "Normal Indoor condition surrounds you";
  m[5] = "Outdoors it is";

  int Index = 0;
  int Max = -1;
  vector<int> Tracker(6, 0);

  for (auto it = myvector.begin(); it != myvector.end(); it++) {
    int LIGHT = it->getvalue();

    if (LIGHT > 0 && LIGHT <= 10) {
      Tracker[0]++;
      if (Tracker[0] >= Max) {
        Max = Tracker[0];
        Index = 0;
      }

    } else if (LIGHT >= 11 && LIGHT <= 50) {
      Tracker[1]++;
      if (Tracker[1] >= Max) {
        Max = Tracker[1];
        Index = 1;
      }
    } else if (LIGHT >= 51 && LIGHT <= 200) {
      Tracker[2]++;
      if (Tracker[2] >= Max) {
        Max = Tracker[2];
        Index = 2;
      }
    } else if (LIGHT >= 201 && LIGHT <= 400) {
      Tracker[3]++;
      if (Tracker[3] >= Max) {
        Max = Tracker[3];
        Index = 3;
      }
    } else if (LIGHT >= 401 && LIGHT <= 5000) {
      Tracker[4]++;
      if (Tracker[4] >= Max) {
        Max = Tracker[4];
        Index = 4;
      }
    } else {
      Tracker[5]++;
      if (Tracker[5] >= Max) {
        Max = Tracker[5];
        Index = 5;
      }
    }
  }

  cout << m[Index];
}
