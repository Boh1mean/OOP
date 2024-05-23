#include <iostream>
#include <string>

//  class entity{
//     protected:
//  std::string name;
//     public:
//         entity(std::string name): name(name){};
//         virtual std::string move(){
//             return "Entity move";
//         }
//         virtual ~entity(){std::cout << "Dest entity" << std::endl;}
//  };

//  class MagicalEntity{
//     protected:
// std::string magic_ability;
//     public:
//         MagicalEntity(std::string magic_ability): magic_ability(magic_ability){};
//         virtual std::string move(){
//             return "MagicalEntity moves magically";
//         }
//         virtual ~MagicalEntity(){std::cout <<" Dest MagicalEntity"<<std::endl;} 
//  };

 class Kikimora {
    std::string name;
    int level_of_strenght;
    friend class B;

    public:
        Kikimora(){std::cout << "Base constr" << std::endl;}
        Kikimora(std::string imya, int levelStr){
            std::cout << "Base param const" << std::endl;
            name = imya;
            level_of_strenght = levelStr;
        }
        ~Kikimora(){std::cout << "Dest Kikimora" << std::endl;}
        friend void f(Kikimora &ob1);
 }; 

 void f(Kikimora &ob1){
    std::cout << "Смените имя" << std::endl; 
    std::cin >> ob1.name;
 }
 class B{
    public:
    static void showKikimora(Kikimora &obS) {
		std::cout << "name =" << obS.name << "\nlevel of strenght = " << obS.level_of_strenght << std::endl;
    }

 };

 int main() {
   Kikimora с("Baba", 30);
	B::showKikimora(с);

	f(с);
	B::showKikimora(с);

}
