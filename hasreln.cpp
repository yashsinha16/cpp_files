#include<iostream>
#include<cstring>
using namespace std;

class Engine
{
    int m_strokes;
    int m_rpm;
    public:
    Engine(int strokes,int rpm):m_strokes(strokes),m_rpm(rpm)
    {

    }
    Engine(const Engine& ref):m_strokes(ref.m_strokes),m_rpm(ref.m_rpm)
    {
    }
    void display(){
    std::cout<<m_strokes<<","<<m_rpm<<"\n";}
    
    //TODO:display
};
class Car
{
    int m_wheels;
    int m_speed;
    Engine m_engine;
    public:
    Car(int wheels,int speed,int strokes,int rpm):
    m_wheels(wheels),m_speed(speed),m_engine(strokes,rpm)//if not here we need to have a default constructor
    {

    }
    Car(const Car& ref):m_wheels(ref.m_wheels),
            m_speed(ref.m_speed),m_engine(ref.m_engine)
    {

    }
    void display()
    {
        m_engine.display();
        std::cout << m_wheels << "," << m_speed << "\n";
    }
};
int main()
{
    Car c1(4,0,4,0);
    c1.display();
    return 0;
}
