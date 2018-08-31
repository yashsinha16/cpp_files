#include "json.hpp"
#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
using json=nlohmann::json;
json encoder;
int main(){
ofstream fout("sample.json");
encoder["temperature"]=24;
encoder["humidity"]=24;
encoder["pressure"]=72;
fout<<encoder.dump()<<"\n";
std::cout<<encoder.dump()<<"\n";
fout.close();
return 0;
}
