/*
Создать класс stipends, содержащий следующие поля: номер
зачетной книжки, фамилия, имя, отчество, номер группы, курс, средний балл
за последнюю сессию, размер стипендии. Перегрузить операторы:
1) ! как унарный метод класса, увеличивающий значение поля курс на 1;
2) -- как унарную дружественную функцию, проверки значения поля
размер стипендии больше 1500 рублей;
3) + как бинарный метод класса, суммирующий значение полей размер
стипендии двух студентов;
4) < как бинарную дружественную функцию, сравнивающую размер
стипендии двух студентов.
*/

#include <iostream>
#include <string>

class Stipends {
   
       int gradebook;
        std::string FullName;
        int groupNum, cours; 
        double avgScore;
        int scholarship;
    public:
        Stipends(){std::cout << "base const" << std::endl;}
        Stipends(int zachetka, std::string fio, int gruppa, int kurs, double ball, int stipendia){
            gradebook = zachetka;
            FullName = fio;
            groupNum = gruppa;
            cours = kurs;
            avgScore = ball;
            scholarship = stipendia;
            std::cout << "Base param" << std::endl;
        }
        
        ~Stipends(){std::cout << "Base dest" << std::endl;}

        void operator!(){
            this -> cours = cours + 1;
            std::cout <<"Итоговый курс"<<cours << std::endl;
        }
        friend void operator--(Stipends &student);

        bool operator+(Stipends &student){
           return this -> scholarship + student.scholarship;
        }

        friend bool operator<(const Stipends &student1, const Stipends &student2);
        
        void show() {
            std::cout << "Зачетка = " << this->gradebook << "\nФамилия и имя = " << this->FullName << "\nГруппа = " << this->groupNum << "\nКурс = " << this->cours <<"\nСредний балл = " << this->avgScore <<"\nРазмер стипендии = " << this->scholarship << std::endl;
        }
    }; 
    
    

    void operator--(Stipends &stipendia){
        stipendia.scholarship--;
        if(stipendia.scholarship > 1500){
            std::cout << "Стипендия студента превышает 1500 рублей.\n";
    } else {
        std::cout << "Стипендия студента не превышает 1500 рублей.\n";
    }
        }
    
    bool operator<(const Stipends &student1, const Stipends &student2){
        if(student1.scholarship < student2.scholarship){
            std::cout <<"Стипендия 1-го студента меньше" <<std::endl;
        }else{
            std::cout << "Стипендия 2-го студента меньше" <<std::endl;
        }
    }

int main(){
   Stipends student1(1, "Иванов Иван Иванович", 101, 1, 4.5, 1500);
   Stipends student2(2, "Петров Петр Петрович", 102, 2, 4.7, 1600);

    student1.show();
    student2.show();

   // Увеличиваем курс студента на 1
   !student1;

   // Проверяем, превышает ли стипендия 1500 рублей
   --student1;
   --student2;

   // Суммируем стипендии двух студентов
   int totalScholarship = student1 + student2;
   std::cout << "Общая сумма стипендий: " << totalScholarship << std::endl;

   // Сравниваем стипендии двух студентов
   if (student1 < student2) {
       std::cout << "Стипендия первого студента меньше стипендии второго студента." << std::endl;
   } else {
       std::cout << "Стипендия второго студента больше." << std::endl;
   }

    
   return 0;
}
