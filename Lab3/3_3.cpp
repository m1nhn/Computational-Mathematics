/*
 * Author : Nguyen Le Minh
 * Group : N3251
 * Laboratory : 3
 */
#include <iostream>
#include <cmath>
#include <vector>
#include "matplotlibcpp.h"
using namespace std;

namespace plt = matplotlibcpp;

double err = 0.001;
double miN = 0, maX = 10;
int points = 5000;
double f(double x){
    return /*function*/;
}

void hord(double min, double max, double err) {
    if (f(min) * f(max) > 0) {
        cout << "It's a bad interval !!!" << endl;
        return;
    }
    for(int i = 0; i < 100; i++){
        min = max - (max - min) * f(max) / (f(max) - f(min));
        max = min + (min - max) * f(min) / (f(min) - f(max));
        if(fabs(max - min) < err){
            cout << "Roots of this equation are : " << max <<endl;
            return;
        }
    }
    cout << "Calculation limit exceeded !" << endl;
}

int main(){
    hord(miN, maX, err);
    double step = (maX - miN)/points;
    std::vector<double> x(points);
    for(int i = 0; i < points; i++)
        x.at(i) = miN + i*step;
    plt::plot(x, [](int d){return 0;}, "r-", x, [](double d) { return f(d); }, "k-"); plt::show();
    return 0;
}