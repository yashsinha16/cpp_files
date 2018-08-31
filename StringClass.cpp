#include<iostream>
#include<cstring>
using namespace std;
class MyString
{
    char *m_buf;
    int m_len;
    public:
    MyString(const char*pstr){
    m_len=strlen(pstr);
    m_buf=new char[m_len+1];
    strcpy(m_buf,pstr);
    }
    MyString(const MyString& ref):m_len(ref.m_len){
        
        m_buf=new char[m_len + 1];
        strcpy(m_buf,ref.m_buf);
        }
    ~MyString(){//if condition insert
        delete[] m_buf;
        }
    MyString operator=(const MyString &ref) {
        m_len=ref.m_len;
        m_buf=new char[m_len + 1];
        strcpy(m_buf,ref.m_buf);
        return m_buf;//if condition insert
        }
        
    void prints() const{
        std::cout << m_buf<<"\n";
    }
    int length() const{
        return m_len;
        
    }
    };  
    int main(){
    MyString s1("abcd");
    s1.prints();
    MyString s2(s1);
    s2.prints();
    MyString s3("xyz");
    s3=s1;//without operator overloading this is shallow copy,leads to memory leak
    s3.prints();
    return 0;
}
