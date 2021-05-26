/*
 * Author : Nguyen Le Minh
 * Group : N3251
 * Laboratory : 3
 */
#include <iostream>
#include <cmath>
#include <vector>
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;
double err = 0.001;
double miN = -10, maX = 10;
int points = 5000;
double f(double x){
    return /*function*/;
}
void divide(double min, double max, double err){ double mid;
    for(int i = 0; i < 1000; i++){
        mid = (min+max)/2; if(f(min) == 0){
            std::cout << "Корень: " << min << std::endl;
            return;
        }
        else if(f(max) == 0){
            std::cout << "Корень: " << max << std::endl; return;
        }
        else if(f(min)*f(mid) < 0)
            max = mid;
        else if(f(mid)*f(max) < 0)
            min = mid;
        else{
            std::cout << "Плохой интервал или нет корней" << std::endl;
            return;
        }
        if(max-min < err){
            std::cout << "Корень: " << (min+max)/2 << std::endl; return;
        } }
    std::cout << "Превышен предел вычислений" << std::endl;
}

int main() {
    divide(miN, maX, err);
    double step = (maX - miN)/points;
    std::vector<double> x(points);
    for(int i=0; i<points; i++)
        x.at(i) = miN + i*step;
    plt::plot(x, [](int d){return 0;}, "r-", x, [](double d) { return f(d); }, "k-"); plt::show();
    return 0;
}