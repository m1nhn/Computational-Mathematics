/*
 * Author : Nguyen Le Minh
 * Group : N3251
 * Lab : 8.3
 */
#include<iostream>
#include<vector>
using namespace std;
//factorial
int fac(int x) {
    if (x <= 1) return 1;
    int result = 1;
    for (int i = 2; i <= x; i++) {
        result *= i;
    }
    return result;
}
double trlen_k(float q,int k,double delta_k) {
    //k k-ой член в пониноме P(x)
    //delta_k k-ой разность x0
    double result = 1;
    for (int i = k-1; i >=0; i--)
    {
        result *= (q - i);
    }
    result = result * delta_k / fac(k);
    return result;
}

void solver(){
    int n;

    cout << "Input N:";//размер последовательности
    cin >> n;
    int num;
    cout << "Input number of pairs value(x,y):";
    cin >> num;
    float start;
    float h;//шаг
    cout << "Input start value x0: ";
    cin >> start;
    cout << "Input step value h:";
    cin >> h;
    auto *x = (float*)malloc(sizeof(float)*num);
    auto *y = (double*)malloc(sizeof(double)*num);
    cout << "Input yi:";
    x[0] = start;
    cin >> y[0];

    //вычислит конечные разности

    vector<vector<double>> delta(n);
    int prev = 0;
    for (int i = 1; i < num; i++)
    {
        x[i] = start + i * h;
        cin >> y[i];
        delta[0].push_back(y[i] - y[prev]);//delta[0][i] первой разность
        prev = i;
    }
    int prev_k;
    for (int k = 1; k < n; k++)
    {
        prev = 0;
        prev_k = k-1;
        for (int i = 1; i < (num - k); i++)
        {
            //delta[k][i] k+1-ти разность
            delta[k].push_back(delta[prev_k][i] - delta[prev_k][prev]);
            prev = i;

        }

    }
    cout << "x y delta_y delta_2y delta_3y" << endl;
    for (int i = 0; i < num-3; i++)
    {
        cout << x[i]<<" " << y[i] << " " << delta[0][i] << " " << delta[1][i] << " " << delta[2][i];
        cout << endl;
    }

    // Интерполяционные формулы Ньютона

    float x0,x_new;//x0 наболее близки к х_new по сравнению с заданной xi,x_new>x0
    cout << "Input x_new to find y_new:";
    cin >> x_new;
    cout << "Input x0 and number of x0 in series:";
    cin >> x0;
    int k;//положение x0 в заданной ряд x
    cin >> k;
    k -= 1;
    float q=(x_new-x0)/h;//число шагов для достижения точки x0
    double Px=y[k];
    for (int i = 1; i <= n; i++)
    {
        cout << trlen_k(q, i, delta[i - 1][k]) << endl;
        Px += trlen_k(q, i, delta[i - 1][k]);
    }
    cout <<"Value Y_new: "<< Px<<endl;

    //производной левой разностью y'=f(x)-f(x0)/(x-x0) при x>x0
    double	df_left = (Px - y[k]) / (x_new - x0);
    cout << "derivative left: " << df_left << endl;
    //производной правой разностью y'=f(x)-f(x0)/(x-x0) при x<x0
    int idx_right = 0;//index x0 where x0>x_new
    for (int i = 0; i < num; i++)
    {
        if (x[i] > x_new) {
            idx_right = i;
            break;
        }
    }
    double	df_right = (Px - y[idx_right]) / (x_new - x[idx_right]);
    cout << "derivative right: " << df_right << endl;
    free(x);
    free(y);

}

int main() {
    solver();
    return 0;
}
