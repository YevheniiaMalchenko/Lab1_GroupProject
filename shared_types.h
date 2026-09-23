#ifndef SHARED_TYPES_H
#define SHARED_TYPES_H

#include <functional>

struct InputData {
    std::function<double(double)> func; // функція
    double a; //ліва межа
    double b;  //права межа 
    double epsilon;//точність
};

struct Result {
    double extremum_x; //точка екстремуму
    double extremum_y; // значення функції в цій точці
    int iterations; 
    int status_code;
};

#endif 