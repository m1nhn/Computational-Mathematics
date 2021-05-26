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
double x_0 = 1;
int points = 50001;
double miN = -1;
double maX = 3;

double f(double x){
    return /*function*/;
};

double df(double x){
    return /*function*/;
}

void newton(double x0, double err){
    double x1 = x0 - f(x0)/df(x0);
    for(int i = 0; i < 1000; i++){
        x0 = x1;
        x1 = x0 - f(x0)/df(x0);
        if(fabs(x0 - x1) < err){
            cout << "Roots of this equation are : " << x1 << endl;
            return;
        }
    }
    cout << "Calculation limit exceeded !" << endl;
}

int main(){
    newton(x_0, err);
    double step = (maX - miN)/points;
    std::vector<double> x(points);
    for(int i=0; i<points; i++)
        x.at(i) = miN + i*step;
    plt::plot(x, [](int d){return 0;}, "r-", x, [](double d) { return f(d); }, "k-"); plt::show();
    return 0;
}

