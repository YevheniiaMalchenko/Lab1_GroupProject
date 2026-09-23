#include <iostream>
#include <iomanip>
#include <memory>

#ifdef _WIN32
#include <windows.h>
#endif

#include "shared_types.h"

using namespace std;

unique_ptr<Result> calculateA(shared_ptr<const InputData> data);
unique_ptr<Result> calculateStudentB(shared_ptr<const InputData> data);

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    auto data = make_shared<InputData>(InputData{
        [](double x) { return x * x; },
        -2.0,
        2.0,
        0.0001
    });

    auto resultA = calculateA(data);
    auto [x, y, iters, status] = *resultA;

    cout << "Метод золотого перерізу студента А\n";
    cout << "Екстремум X: " << x << "\n";
    cout << "Екстремум Y: " << y << "\n";
    cout << "Ітерації : " << iters << "\n\n";

    auto resultB = calculateStudentB(data);
    const auto [extremumX, extremumY, iterations, statusCode] = *resultB;

    if (statusCode == 0)
    {
        std::cout << std::fixed << std::setprecision(8);
        std::cout << "Метод дихотомії — Студент Б\n";
        std::cout << "Координата мінімуму: x = " << extremumX << '\n';
        std::cout << "Значення функції: f(x) = " << extremumY << '\n';
        std::cout << "Кількість ітерацій: " << iterations << '\n';
    }
    else
    {
        std::cerr << "Помилка: некоректні вхідні дані.\n";
        return 1;
    }

    return 0;
}