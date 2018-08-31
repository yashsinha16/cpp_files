#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
int main()

{
int i=0;
ofstream fout("sample.txt");
fout<<"hello file"<<"\n";
fout.write("abcde");
for(i=1;i<=26;i++){
    fout.put(64 + i);}
fout.close();
return 0;
}
