#include <iostream>
#include <string> 

class WarmBloodedVertebrates {
    public:
        double BodyTemperature;
        WarmBloodedVertebrates();
        WarmBloodedVertebrates(double temp);
        ~WarmBloodedVertebrates();
        void f();
};

class Bird:  public WarmBloodedVertebrates { 
    public:
        char Wingspan;
        bool FlyingAbility;
        Bird();
        Bird(double temp, int size, bool ability);
        ~Bird();
        void f();
};

class pigeon: public Bird {
    public:
        std::string PlumageColor;
        double Weight;
        pigeon();
        pigeon(double temp, int size, bool ability, std::string color, double ves);
        ~pigeon();
        void f();
};

WarmBloodedVertebrates::WarmBloodedVertebrates(){BodyTemperature = 36.6;}
WarmBloodedVertebrates::WarmBloodedVertebrates(double temp){BodyTemperature = temp;}
void WarmBloodedVertebrates::f(){std::cout << BodyTemperature << std::endl;}
WarmBloodedVertebrates::~WarmBloodedVertebrates(){;}

Bird::Bird(){Wingspan = 30, FlyingAbility = true;}
Bird::Bird(double temp, int size, bool ability){Wingspan = size, FlyingAbility = ability;}
void Bird::f(){std::cout << "Температура тела: " << BodyTemperature << " "<< "Размах крыльев:" << Wingspan<< " " << "Способность летать: " << FlyingAbility << std::endl;}
Bird::~Bird(){;}

pigeon::pigeon(){PlumageColor = "white", Weight = 2;}
pigeon::pigeon(double temp, int size, bool ability, std::string color, double ves){PlumageColor = color, Weight = ves;}
void pigeon::f(){std::cout << "Температура тела: " << BodyTemperature << " " << "Размах крыльев: " << Wingspan << " " << "Способность летать: " << FlyingAbility << " " 
                            << "Цвет: " <<PlumageColor << " " << "Вес: " << (int)Weight << std::endl;}
pigeon::~pigeon(){;}

int main(){
    std::cout << "Если хотите оставить стандартные значения: Введите 1 в ином случае 0" << std::endl;
    int n;
    std::cin >> n;
    if(n == 1){
        WarmBloodedVertebrates ob1;
        Bird ob2;
        pigeon ob3;
        ob1.f();
        ob2.f();
        ob3.f();
    } else {
        double temp;
        int size;
        bool ability;
        std::string color;
        double ves;
        
        std::cout << "Введите температуру тела, размер крыльев, способность летать (1 - да, 0 - нет), цвет оперения и вес голубя:" << std::endl;
        std::cin >> temp >> size >> ability >> color >> ves;
        WarmBloodedVertebrates ob1(temp);
        Bird ob2(temp, size, ability);
        pigeon ob3(temp, size, ability, color, ves);
        ob1.f();
        ob2.f();
        ob3.f();
    }
    return 0;
}
