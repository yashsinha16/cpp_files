#include "json.hpp"
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
using namespace std;
using json = nlohmann::json;
class rpy {
private:
  double x;
  double y;
  double z;
  

public:
  rpy(double r, double p, double y)
      : x(r), y(p), z(y) {}
  void display() { cout << x << "\t" << y << "\t" << z << "\t";}
  double getvalue(string s) {
    if (s == "x")
      return x;
    else if (s == "y")
      return y;
    else if (s == "z")
      return z;
  }
  };
  vector<rpy> ReadingData(json j_complete) {
   std::vector<rpy> myvector;
    
    for (auto entry : j_complete) {
      rpy newrpy(entry.value("ACC_X", 0.0l), entry.value("ACC_Y", 0.0l),
                 entry.value("ACC_Z", 0.0l));
      myvector.push_back(newrpy);
    }
    return myvector;
  }
     
  void DisplayReading(vector<double> v){
  for (auto it = v.begin(); it != v.end(); it++) {
    cout<<*it<<endl;
    }
    }
    
  int main(){
  
  std::ifstream fin("data.json");
  json parsed_data = json::parse(fin); 
  vector<rpy> myvector = ReadingData(parsed_data);
  std::vector<double> roll;
  std::vector<double> pitch;
  std::vector<double> yaw;
   
  for (auto it = myvector.begin(); it != myvector.end(); it++) {
    double ACC_X = it->getvalue("x");
    double ACC_Y = it->getvalue("y");
    double ACC_Z = it->getvalue("z");

    double pr1 = atan2((-1)*ACC_X, sqrt(ACC_Y*ACC_Y + ACC_Z*ACC_Z));
    double pr2 = atan(ACC_Z / sqrt(ACC_X * ACC_X + ACC_Y * ACC_Y));
    double pr3 = atan(ACC_Y / sqrt(ACC_X * ACC_X + ACC_Z * ACC_Z));
    roll.push_back(pr3);
    pitch.push_back(pr1);
    yaw.push_back(pr2);
    
    }
    cout<<"Roll Readings:::: "<<endl;
    DisplayReading(roll);
    cout<<"Pitch Readings:::: "<<endl;
    DisplayReading(pitch);
    cout<<"Yaw Readings:::: "<<endl;
    DisplayReading(yaw);
    
  
    cout<<"NO OF DATA POINTS: "<<roll.size();
    }

    
