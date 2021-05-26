/*
 * Author : Nguyen Le Minh
 * Group : N3251
 * Lab : 9.1
 */
#include<iostream>
#include<cmath>
using namespace std;
float f1(float x)
{
    return x * x;
}
float f2(float x)
{
    return sin(x) * sin(x);
}
float f3(float x)
{
    return sin(2 * x) + cos(7 * x) + 8;
}
float f4(float x)
{
    return 2 * pow(x, 4) + pow(x, 3) + 2 * pow(x, 2) + 3 * x + 24;
}

float f5(float x)
{
    return log(x * x + 1) + sin(x / 3) + 17;
}

float f6(float x)
{
    return pow(5, x) + sin(x) + x + 11;
}

float f7(float x)
{
    return pow(x, 5) + 2 * pow(x, 4) + 3 * pow(x, 3) + 4 * pow(x, 2) + 5 * x +6;
}

float integral(float f(float), float a, float b, int n)
{
    float s = (f(a) + f(b)) / 2;
    float dx = (b - a) / n;
    for (int i = 0; i < n - 1; i++)
    {
        s += f(a + dx * (i + 1));
    }
    return dx * s;
}

void solver(){
    int n = 100000;
    cout << "F1 = " << integral(f1, -5, 5, n) << endl;
    cout << "F2 = " << integral(f2, -3.14, 3.14, n) << endl;
    cout << "F3 = " << integral(f3, -3.14, 3.14, n) << endl;
    cout << "F4 = " << integral(f4, -1, 3, n) << endl;
    cout << "F5 = " << integral(f5, -100, 100, n) << endl;
    cout << "F6 = " << integral(f6, -3.14, 3.14, n) << endl;
    cout << "F7 = " << integral(f7, -7, 7, n) << endl;
}

int main()
{
    solver();
    return 0;
}