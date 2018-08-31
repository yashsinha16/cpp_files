#include<iostream>
using namespace std;

int *parr,len=10;

int main()
{
parr= new int[len];
for(int i=0;i<len;i++)
    parr[i]=rand()%100;
for(int i=0;i<len;i++)
    cout << parr[i] << "\n";
delete[] parr;
}
