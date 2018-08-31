#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
int main()
{
char ch;
string str;
std::ifstream fin("sample.txt");
//fin>>ch;
//fin>>str;
fin.unsetf(ios::skipws);
while(true){
    fin>>str;
    if(fin.eof()) break;
    cout.write(str.c_str(),str.length());
    }
    fin.close();
    } 
    
