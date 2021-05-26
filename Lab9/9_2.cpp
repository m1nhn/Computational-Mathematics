/*
 * Author : Nguyen Le Minh
 * Group : N3251
 * Lab : 9.2
 */
#include <iostream>
#include <cmath>

using namespace std;

double testFunction(double x){
    return pow(x,5) + 2*pow(x,4) + 3*pow(x,3) + 4*pow(x,2) + 5*x + 6;
}

int main() {
    double a, b, steps;
    cout << "Введите границы a, b и количество разбиений через пробел:\n";
    cin >> a >> b >> steps;
    double step = (b - a) / steps;
    double integral = 0;
    for (int i = 0; i < steps; i++) {
        integral += testFunction(a + i * step) * step;
    }
    cout << "Интеграл: " << integral;
    return 0;
}