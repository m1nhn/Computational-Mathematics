/*
 * Author : Nguyen Le Minh
 * Group : N3251
 * Laboratory : 3
 */
#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

typedef complex<double> comp;

double eps;

comp fx1(comp z) {
    return 4.0* pow(z, 4) + 2.0 * pow(z, 2) + 1.3;
}
comp dfx1(comp z) {
    return 16.0* pow(z, 3) + 4.0 * z;
}

comp fx2(comp z) {
    return pow(z, 2) + 2.71;
}
comp dfx2(comp z) {
    return 2.0* z;
}

comp fx3(comp z) {
    return 2.0* exp(z) + sqrt(2.0);
}
comp dfx3(comp z) {
    return 2.0* exp(z);
}

comp solve(comp fz(comp), comp dfz(comp), comp z0) {
    comp z1 = z0 - fz(z0) / dfz(z0);
    int iterations = 0;

    while (abs(z1.real() - z0.real()) > eps || abs(z1.imag() - z0.imag()) > eps) {
        iterations++;
        z0 = z1;
        z1 = z0 - fz(z0) / dfz(z0);
    }

    return z1;
}

int main() {
    comp x0 = 1.0 + 1.0i;
    int number;
    cout << "Please enter the number of equation " << endl;
    cin >> number;

    cout << "Enter the margin of error:  " << endl;
    cin >> eps;

    switch (number) {
        case 1: {
            cout << "x = " << solve(fx1, dfx1, x0) << endl;
            break;
        }
        case 2: {
            cout << "x = " << solve(fx2, dfx2, x0) << endl;
            break;
        }
        case 3: {
            cout << "x = " << solve(fx3, dfx3, x0) << endl;
            break;
        }
    }

    return 0;
}



