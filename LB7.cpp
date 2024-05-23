#include <iostream>
#include <vector>

// Функция-шаблон для заполнения массива
template <typename T>
void fillArray(std::vector<T>& arr, int size) {
    for(int i = 0; i < size; i++) {
        std::cout << "Введите элемент " << i+1 << ": ";
        T element;
        std::cin >> element;
        arr.push_back(element);
    }
}

// Функция-шаблон для вывода элементов массива на экран
template <typename T>
void printArray(const std::vector<T>& arr) {
    for(const auto& element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// Функция-шаблон, записывающая массив в обратном порядке
template <typename T>
std::vector<T> reverseArray(const std::vector<T>& arr) {
    std::vector<T> reversed(arr.rbegin(), arr.rend());
    return reversed;
}

int main() {
    std::vector<int> arrInt;
    fillArray(arrInt, 3);
    printArray(arrInt);
    arrInt = reverseArray(arrInt);
    printArray(arrInt);

    std::vector<char> arrChar;
    fillArray(arrChar, 3);
    printArray(arrChar);
    arrChar = reverseArray(arrChar);
    printArray(arrChar);

    std::vector<double> arrDouble;
    fillArray(arrDouble, 3);
    printArray(arrDouble);
    arrDouble = reverseArray(arrDouble);
    printArray(arrDouble);

    return 0;
}
