/*
 * Author : Nguyen Le Minh
 * Group : N3251
 * Lab : 6
 */

#include <complex>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

#define pi 3.14159265358979323846
typedef complex<double> base;

void fft (std::vector<base> & a, bool invert) {
    int n = (int) a.size();
    if (n == 1)  return;
    std::vector<base> a0 (n/2),  a1 (n/2);
    for (int i=0, j=0; i<n; i+=2, ++j) {
        a0[j] = a[i];
        a1[j] = a[i+1];
    }
    fft (a0, invert);
    fft (a1, invert);
    double ang = 2*pi/n * (invert ? -1 : 1);
    base w (1),  wn (cos(ang), sin(ang));
    for (int i=0; i<n/2; ++i) {
        a[i] = a0[i] + w * a1[i];
        a[i+n/2] = a0[i] - w * a1[i];
        if (invert)
            a[i] /= 2,  a[i+n/2] /= 2;
        w *= wn;
    }
}

void solver(){
    int N;
    bool check;
    cout << "Введите 0, если хотите прямое преобразование Фурье или 1 если обратное: ";
    cin >> check;
    complex<double> buff;
    cout << "Введите длину последовательности (степень двойки): ";
    cin >> N;
    vector<base> a(N);
    cout << "Введите комплексные числа вида (a,b)" << std::endl;
    for(int i = 0; i < N; i ++){
        cout << "Введите комплексное число [" << i << "]: ";
        cin >> buff;
        a[i] = buff;
    }
    fft(a, check);
    cout << "Ответ: " << std::endl;
    for(int i = 0; i < N; i++) {
        cout << a[i];
    }
}

int main(){
    solver();
    return 0;
}
