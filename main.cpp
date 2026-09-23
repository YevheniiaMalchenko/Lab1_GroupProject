#include <iostream>
using namespace std;
#include "shared_types.h"
#include <memory>
unique_ptr<Result> calculateA(shared_ptr<const InputData> data);

int main() {
    auto data = make_shared<InputData>(InputData{
        [](double x) { return x * x; },
        -2.0,
        2.0,
        0.0001
    });

    auto resultA = calculateA(data); //виклик функції
    auto [x, y, iters, status] = *resultA; //результа за допомогою structured bindings

    cout << "Метод золотого перерізу студента А\n";
    cout << "Екстремум X: " << x << "\n";
    cout << "Екстремум Y: " << y << "\n";
    cout << "Ітерації: " << iters << "\n";
    return 0;
}