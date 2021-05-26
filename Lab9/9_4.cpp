/*
 * Author : Nguyen Le Minh
 * Group : N3251
 * Lab : 9.4
 */
#include <iostream>
#include <cmath>

using namespace std;

double f(double x){
    return pow(x,5) + 2*pow(x,4) + 3*pow(x,3) + 4*pow(x,2) + 5*x + 6;
}

void solver(){
    double a, b, eps, I, I1 = 0;
    cout << "Введите границы a, b и желаемую точность через пробел:\n";
    cin >> a >> b >> eps;
    I = eps + 1;
    for (int N = 2; (N <= 4) || (fabs(I1 - I) > eps); N *= 2) {
        double h, sum2 = 0, summ = 0, sum = 0; h = (b - a)/(2*N);
        for (int i = 1; i < 2 * N; i += 2) {
            summ += f(a + h*i);
            sum2 += f(a + h*(i + 1)); }
        sum = f(a) + 4*summ + 2*sum2 - f(b); I = I1;
        I1 = (h / 3) * sum;
    }
    cout << "Интеграл: " << I1 << endl;
}

int main(){
    solver();
    return 0;
}