#include <iostream>
#include <cmath>
#include <windows.h>
#include <limits>
#include <numeric>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    /* Проверка ввода данных (справочно)
    while(true)
    {
        float value; // попробуйте разные типы данных
        std::cin >> value;

        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cerr << "Ошибка ввода данных\n";

            // Данные две строки необходимы для очистки буфера ввода, без них, при последующем вводе данных, произойдёт зацикливание:
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Если нужно прервать программу:
            // return 1; // выход из функции main, соответственно и из программы
            // exit(1); // а так можно выйти из программы в любом месте
            // цифры - это номера ошибок передаваемые программой в ОС,
            // 0 - всё хорошо, не 0 - какой-то код, который разработчик устанавливает сам...
        }
        else
            std::cout << value << '\n';
    }

    return 0;
     */
    float startAmplitude;
    float amplitude;
    float endAmplitude;
    int oscillations;
    while (true) {
        oscillations=0;
        std::cout<<"Введите начальную амплитуду (м, >0): ";
        std::cin>>startAmplitude;
        std::cout<<"Введите конечную амплитуду (м, >0, но меньше начальной амплитуды): ";
        std::cin>>endAmplitude;
        amplitude=startAmplitude;
        if (startAmplitude<=endAmplitude || endAmplitude<0 || startAmplitude<0 || std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Ошибка ввода данных\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            while (amplitude>endAmplitude) {
                amplitude=(100-8.4)/100*amplitude;
                oscillations++;
            }
            std::cout << "Количество колебаний: "<<oscillations<<"\n";
        }
    }
}