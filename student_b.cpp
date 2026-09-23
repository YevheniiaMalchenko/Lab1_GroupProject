#include "shared_types.h"

#include <memory>

std::unique_ptr<Result> calculateStudentB(
    std::shared_ptr<const InputData> data)
{
    // Проверка корректности входных данных
    if (!data ||
        !data->func ||
        data->a >= data->b ||
        data->epsilon <= 0.0)
    {
        return std::make_unique<Result>(
            Result{0.0, 0.0, 0, -1}
        );
    }

    double left = data->a;
    double right = data->b;

    // Малое смещение относительно середины интервала
    const double delta = data->epsilon / 4.0;

    int iterations = 0;

    // Метод дихотомии для поиска минимума
    while ((right - left) > data->epsilon)
    {
        const double middle = (left + right) / 2.0;

        const double x1 = middle - delta;
        const double x2 = middle + delta;

        const double y1 = data->func(x1);
        const double y2 = data->func(x2);

        if (y1 < y2)
        {
            right = x2;
        }
        else
        {
            left = x1;
        }

        ++iterations;
    }

    const double extremumX = (left + right) / 2.0;
    const double extremumY = data->func(extremumX);

    return std::make_unique<Result>(
        Result{extremumX, extremumY, iterations, 0}
    );
}