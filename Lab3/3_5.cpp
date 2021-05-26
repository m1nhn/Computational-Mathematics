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
double x_0 = 1.2;
int points = 5000;
double miN = 0;
double maX = 5;

double f(double x){
    return /*function*/;
}

double ff(double x){
    return /*function*/;
}

void iter(double x, double err){
    double x0; int iter = 0;
    do{
        x0 = x;
        x = ff(x); iter++;
    } while (fabs(x0 - x) > err && iter<30000);
    cout << "Root of this equation is: "<< x << endl;
}

int main(){
    iter(x_0, err);
    double step = (maX - miN)/points;
    std::vector<double> x(points);
    for(int i=0; i<points; i++) {
        x.at(i) = miN + i * step;
    }
    plt::plot(x, [](int d){return 0;}, "r-", x, [](double d) { return f(d); }, "k-"); plt::show();
    return 0;
}
