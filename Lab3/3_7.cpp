/*
 * Author : Nguyen Le Minh
 * Group : N3251
 * Laboratory : 3
 */
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef vector<double> polynome;
const double eps = 0.000001;

double x(int num, int max, polynome& coeffs) {
    double cases[] = {0.0, 0.0, 0.0, 0.0, 1.0};
    if (num <= max) {
        return cases[num];
    }
    double retval = 0;
    for (int j = 1; j < coeffs.size(); j++) {
        retval += -coeffs[j] * x(num - j, max, coeffs);
    }
    return retval;
}

double calc(double y, polynome& coeffs) {
    int n = coeffs.size();
    double res = 0.0;
    for (int i = 0; i < n; i++) {
        res += pow(y, n-i-1)*coeffs[i];
    }
    return res;
}

polynome f = {1.0, 5.0, 0.0, 0.0, 0.0, -5.0};

double bernoulli(polynome& f) {
    int n = f.size()-1;
    int k = 0;
    double approx = x(n,n-1,f)/x(n-1,n-1,f);
    while (abs(calc(approx, f)) > eps) {
        k++;
        approx = x(n+k,n-1,f)/x(n+k-1,n-1,f); }
    cout << "Iterations: " << k << endl;
    return approx;
}

int main() {
    cout << bernoulli(f) << endl;
    return 0;
}
