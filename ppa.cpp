/*
Описать тип данных с именем stipends, содержащий следующие поля:
номер зачетной книжки, фамилия, имя, отчество, номер группы, курс, средний балл
за последнюю сессию, размер стипендии.
Способ обработки – вывод на дисплей фамилии и имени студента, если размер
его стипендии выше значения, заданного пользователем, иначе вывести
соответствующее сообщение.
*/

#include <iostream>
#include <string>

class Stipends {
    private: 
        int gradebook;
        std::string Name;
        std::string Secondname;
        char groupNum, cours, avgScore;
        int scholarship;
    public:
        Stipends();
        void Entrance();
        void Calculation();
    }; 

Stipends::Stipends(){
    std::cout << "Введите номер зачетной книжки" << std::endl;
    std::cin >> gradebook;

    std::cout << "Введите имя и фамилию" << std::endl;
    std::cin >> Name >> Secondname;

    std::cout << "Введите номер группы" << std::endl;
    std::cin >> groupNum;

    std::cout << "Введите курс обучения" << std::endl;
    std::cin >> cours;

    std::cout << "Введите средний балл" << std::endl;
    std::cin >> avgScore;

    std::cout << "Размер стипендии" << std::endl;
    std::cin >> scholarship;
}

void Stipends::Entrance(){
   std::cout << "Фамилия и Имя студента: " << Secondname << " " << Name << std::endl;
}

void Stipends::Calculation(){
    double stipend;
    std::cout << "Введите размер стипендии: ";
    std::cin >> stipend;
    if(scholarship >= stipend){
        std::cout << "Фамилия и имя: " << Secondname << " " << Name << std::endl;
    }else{
        std::cout <<"Все впорядке" << std::endl;
    }
}

int main(){
    Stipends ob1;
    Stipends ob2;

   while (true) {
        std::cout << "1. Ввод данных\n2. Вывод данных\n3. Выход\n";
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                ob1.Entrance();
                ob2.Entrance();
                break;
            case 2:
                ob1.Calculation();
                ob2.Calculation();
                break;
            case 3:
                return 0;
            default:
                std::cout << "Неверный выбор\n";
        }
    }

}