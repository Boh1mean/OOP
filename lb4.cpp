#include <iostream>
#include <string>

 class entity{
    protected:
 std::string name;
    public:
        entity(std::string name): name(name){};
        virtual std::string move(){
            return "Entity move";
        }
        virtual ~entity(){std::cout << "Dest entity" << std::endl;}
 };

 class MagicalEntity{
    protected:
std::string magic_ability;
    public:
        MagicalEntity(std::string magic_ability): magic_ability(magic_ability){};
        virtual std::string move(){
            return "MagicalEntity moves magically";
        }
        virtual ~MagicalEntity(){std::cout <<" Dest MagicalEntity"<<std::endl;} 
 };

 class Kikimora : public entity, public MagicalEntity{
    protected:
int level_of_evil;
int level_of_strength;
    public:
    Kikimora(std::string name, std::string magic_ability, int level_of_evil, int level_of_strength)
        : entity(name), MagicalEntity(magic_ability), level_of_evil(level_of_evil), level_of_strength(level_of_strength) {}

     std::string move() {
        return "Kikimora moves quickly and magically";
    }

    std::string attack() {
        return "Kikimora attacks with a strength level of " + std::to_string(level_of_strength);
    }
    ~Kikimora(){std::cout << "Dest Kikimora" << std::endl;}
 }; 

 int main() {
    Kikimora k1("Kiki", "Fire", 7, 10);
    

    std::cout << k1.move() << std::endl;
    std::cout << k1.attack() << std::endl;

    Kikimora* k2 = new Kikimora("Mora", "Water", 5, 8); 
    std::cout << k2->move() << std::endl;
    std::cout << k2->attack() << std::endl;

    delete k2; 

    return 0;
}
