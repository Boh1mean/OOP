/*
*/

#include <iostream>
#include <string> 

class WarmBloodedVertebrates {
    public:
        double BodyTemperature;
        WarmBloodedVertebrates();
        WarmBloodedVertebrates(double temp);
        virtual ~WarmBloodedVertebrates();
        virtual void f() = 0;
};

class Bird:  public WarmBloodedVertebrates { 
    public:
        int Wingspan;
        bool FlyingAbility;
        Bird();
        Bird(double temp, int size, bool ability);
        virtual ~Bird();
        void f();
};

class pigeon: public Bird {
    public:
        std::string PlumageColor;
        double Weight;
        pigeon();
        pigeon(double temp, int size, bool ability, std::string color, double ves);
        virtual ~pigeon();
        void f();
};

WarmBloodedVertebrates::WarmBloodedVertebrates(){BodyTemperature = 36.6;}
WarmBloodedVertebrates::WarmBloodedVertebrates(double temp){BodyTemperature = temp;}
void WarmBloodedVertebrates::f(){std::cout << BodyTemperature << std::endl;}
WarmBloodedVertebrates::~WarmBloodedVertebrates(){std::cout<< "WBV dest was worked" << std::endl;}

Bird::Bird(){Wingspan = 30, FlyingAbility = true;}
Bird::Bird(double temp, int size, bool ability):WarmBloodedVertebrates(temp){
    Wingspan = size, FlyingAbility = ability;
    }
void Bird::f(){std::cout << "Температура тела: " << BodyTemperature << " "<< "Размах крыльев:" << Wingspan<< " " << "Способность летать: " << FlyingAbility << std::endl;}
Bird::~Bird(){std::cout << "Bird dest was worked" << std::endl;}

pigeon::pigeon(){PlumageColor = "white", Weight = 2;}
pigeon::pigeon(double temp, int size, bool ability, std::string color, double ves) : Bird(temp, size, ability), PlumageColor(color), Weight(ves){
    PlumageColor = color, Weight = ves;
    }
void pigeon::f(){std::cout << "Температура тела: " << BodyTemperature << " " << "Размах крыльев: " << Wingspan << " " << "Способность летать: " << FlyingAbility << " " 
                            << "Цвет: " <<PlumageColor << " " << "Вес: " << Weight << std::endl;}
pigeon::~pigeon(){std::cout << "pigeon dest was worked" << std::endl;}

int main(){
    std::cout << "Если хотите оставить стандартные значения: Введите 1 в ином случае 0" << std::endl;
    int n;
    std::cin >> n;
    
    if(n == 1){
     WarmBloodedVertebrates *ob2;
     WarmBloodedVertebrates *ob3;
        ob2 = new Bird;
        ob3 = new pigeon;

        ob2 -> f();
        ob3 -> f();

         delete ob2;
         delete ob3;

    } else {
        double temp;
        int size;
        bool ability;
        std::string color;
        double ves;
        
        std::cout << "Введите температуру тела, размер крыльев, способность летать (1 - да, 0 - нет), цвет оперения и вес голубя:" << std::endl;
        std::cin >> temp >> size >> ability >> color >> ves;
        WarmBloodedVertebrates *ob2;
        WarmBloodedVertebrates *ob3;
       ob2 = new Bird(temp, size, ability);
       ob3 = new pigeon(temp, size, ability, color, ves);

       ob2 -> f();
       ob3 -> f();

       delete ob2;
       delete ob3;
    }
    return 0;
}
