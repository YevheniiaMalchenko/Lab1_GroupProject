#include <iostream>
#include <iomanip>
#include <memory>

#ifdef _WIN32
#include <windows.h>
#endif

#include "shared_types.h"

// Объявление функции
std::unique_ptr<Result> calculateStudentB(
    std::shared_ptr<const InputData> data);

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    std::cout << "Лабораторна робота №1, Мальченко/Слюсар\n";
    std::cout << "Метод дихотомії — Студент Б\n\n";

    auto data = std::make_shared<const InputData>(
    InputData{
        [](double x)
        {
            return x * x;
        },
        -2.0,
        2.0,
        0.0001
    }
);

    // Вызов функции 
    auto resultB = calculateStudentB(data);

    // Получение полей результата через structured bindings
    const auto [extremumX, extremumY, iterations, statusCode] = *resultB;

    if (statusCode == 0)
    {
        std::cout << std::fixed << std::setprecision(8);
        std::cout << "Інтервал пошуку: ["
                  << data->a << "; " << data->b << "]\n";
        std::cout << "Точність: " << data->epsilon << '\n';
        std::cout << "Координата мінімуму: x = "
                  << extremumX << '\n';
        std::cout << "Значення функції: f(x) = "
                  << extremumY << '\n';
        std::cout << "Кількість ітерацій: "
                  << iterations << '\n';
    }
    else
    {
        std::cerr << "Помилка: некоректні вхідні дані.\n";
        return 1;
    }

    return 0;
}