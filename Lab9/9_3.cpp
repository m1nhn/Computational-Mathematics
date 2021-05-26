/*
 * Author : Nguyen Le Minh
 * Group : N3251
 * Lab : 9.3
 */
#include <iostream>
#include <cmath>

using namespace std;

double f(double x){
    return pow(x,5) + 2*pow(x,4) + 3*pow(x,3) + 4*pow(x,2) + 5*x + 6;
}

void solver(){
    double a, b, steps;
    cout << "Введите границы a, b и количество разбиений через пробел:\n";
    cin >> a >> b >> steps;
    double step = (b-a)/steps;
    double integral = 0;
    double left;
    for(int i = 0; i < steps - 1; i++) {
        left = f(a + step * i);
        integral += (left * step + (f(a + step * (i + 1)) - left) * step / 2);
    }
    cout << "Интеграл: " << integral;
}

int main(){
    solver();
    return 0;
}