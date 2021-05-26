/*
 * Author : Nguyen Le Minh
 * Group : N3251
 * Lab : 8.1
 */
#include <iostream>
#include <cmath>
#include "matplotlibcpp.h"
using namespace std;
namespace plt = matplotlibcpp;

const int a = 0;
const int b = 10;
const int steps = 10;

double f(double x){
    return 4*pow(x,3) + pow(x,2) - 2*x + 3;
}

void solver(){
    double d1[2][steps - 1];
    double d2[2][steps - 2];
    double d3[2][steps - 3];
    double step = (double)(b - a)/steps;
    for(int i = 0; i < steps - 1; i++){
        d1[0][i] = (-f(a + i*step) + f(a + (i + 1)*step))/step;
        d1[1][i] = a + i*step + step/2;
    }
    for(int i = 0; i < steps - 2; i++){
        d2[0][i] = (-d1[0][i] + d1[0][i+1])/step;
        d2[1][i] = a + i*step + step/2;
    }
    for(int i = 0; i < steps - 3; i++){
        d3[0][i] = (-d2[0][i] + d2[0][i+1])/step;
        d3[1][i] = a + i*step + step/2;
    }
    //красный - первая производная
    plt::plot(d1[1], d1[0], "r-");
    //серый - вторая производная
    plt::plot(d2[1], d2[0], "k-");
    //синий - третья производная
    plt::plot(d3[1], d3[0], "b-");
    plt::show();
    for (int i = 0; i < steps-2; i++)
        cout << "d1("<< d1[1][i] << ", " << d1[0][i] << ") d2(" << d2[1][i] << ", " << d2[0][i] << ") d3(" << d3[1][i] << ", " << d3[0][i] << ")" << endl;
}

int main(){
    solver();
    return 0;
}
