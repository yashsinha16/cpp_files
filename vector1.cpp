#include<iostream>
#include<vector>
int main(){
std::vector<int>v1(10);
v1.push_back(10);
v1.push_back(15);
v1.push_back(20);
int sum=0;
int sum1=0;
for(int i=0;i<v1.size();i++){
    v1.at(i)=rand();
    std::cout<<v1.at(i)<<"\n";}
for(auto x:v1){
    sum1+=x;}
std::vector<int>::iterator iter;
for(iter =v1.begin();iter!=v1.end();++iter)
{
    //std::cout<<*iter<<"\n";}
    //std::cout<<sum<<"\n";
    //std::cout<<sum1<<"\n";
    
}
}
