#include<iostream>
#include<map>
int main(){
std::map<int,std::string> names;
    names[101]="hello1";
    names[102]="hello2";
    names[103]="hello3";
    names.insert(std::pair<int,std::string>(104,"hello4"));
    
    for(auto entry:names)
    {
    std::cout<<entry.first<<","<<entry.second<<"\n";
    }
    for(auto iter=names.begin();iter!=names.end();++iter)
    {
    std::cout<<iter->first<<","<<iter->second<<"\n";
    }
    }
    
