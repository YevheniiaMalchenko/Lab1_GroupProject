#include "shared_types.h"
using namespace std;
#include <memory>
#include <cmath>

unique_ptr<Result> calculateA(shared_ptr<const InputData> data) {
    auto res = make_unique<Result>();
    
    double a = data->a;
    double b = data->b;
    double eps = data->epsilon;
    auto f = data->func;

    const double phi = (1.0 + sqrt(5.0)) / 2.0;
    const double resphi = 2.0 - phi;

    double x1 = a + resphi * (b - a);
    double x2 = b - resphi * (b - a);
    double f1 = f(x1);
    double f2 = f(x2);

    int iter = 0;
    while ((b - a) / 2.0 > eps) {
        iter++;
        if (f1 < f2) { 
            b = x2;
            x2 = x1;
            f2 = f1;
            x1 = a + resphi * (b - a);
            f1 = f(x1);
        } else {
            a = x1;
            x1 = x2;
            f1 = f2;
            x2 = b - resphi * (b - a);
            f2 = f(x2);
        }
    }

    res->extremum_x = (a + b) / 2.0;
    res->extremum_y = f(res->extremum_x);
    res->iterations = iter;
    res->status_code = 0;

    return res;
}