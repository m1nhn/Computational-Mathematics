/*
 * Author : Nguyen Le Minh
 * Group : N3251
 * Lab : 7
 */
/*
 * Author : Nguyen Le Minh
 * Group : N3251
 * Lab : 7
 */
#include<iostream>
#include<vector>
using namespace std;

int fac(int x) {
    if (x <= 1) return 1;
    int result = 1;
    for (int i = 2; i <= x; i++) {
        result *= i;
    }
    return result;
}
//k-ой член первая интерполяционная формула Гаусса
double trlen_k_Gauss_1(float q, int k, vector<vector<double>> delta_k,int index_x0) {
    //k k-ой член в пониноме P(x)
    //delta_k k-ой разность x0
    double result = 1;
    int tmp;
    if (k % 2 == 1) {
        tmp = (k - 1) / 2;//tmp=n-1
        q = q + tmp;
        for (int i = 0; i < k; i++)
        {
            result *= (q - i);
        }
        result = result * delta_k[k-1][index_x0-tmp] / fac(k);
    }
    else
    {
        tmp = k / 2 - 1;
        q += tmp;
        for (int i = 0; i < k; i++)
        {
            result *= (q - i);
        }
        result = result * delta_k[k - 1][index_x0 - k/2] / fac(k);
    }

    return result;
}
//k-ой член вторая интерполяционная формула Гаусса
double trlen_k_Gauss_2(float q, int k, vector<vector<double>> delta_k, int index_x0) {
    //k k-ой член в пониноме P(x)
    //delta_k k-ой разность x0
    double result = 1;
    int tmp;
    if (k % 2 == 1) {
        tmp = (k - 1) / 2;//tmp=n-1
        q = q + tmp;
        for (int i = 0; i < k; i++)
        {
            result *= (q - i);
        }
        result = result * delta_k[k - 1][index_x0 - tmp-1] / fac(k);
    }
    else
    {
        tmp = k / 2 - 1;
        q += tmp;
        for (int i = 0; i < k; i++)
        {
            result *= (q - i);
        }
        result = result * delta_k[k - 1][index_x0 - k / 2] / fac(k);
    }

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

    vector<vector<double>> delta(n); //delta[k][i] k+1-ти разность
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
        prev_k = k - 1;
        for (int i = 1; i < (num - k); i++)
        {
            //delta[k][i] k+1-ти разность
            delta[k].push_back(delta[prev_k][i] - delta[prev_k][prev]);
            prev = i;

        }

    }
    cout << "x y delta_y delta_2y delta_3y" << endl;
    for (int i = 0; i < num - 3; i++)
    {
        cout << x[i] << " " << y[i] << " " << delta[0][i] << " " << delta[1][i] << " " << delta[2][i];
        cout << endl;
    }

    // Интерполяционные формулы Gauss

    float x0, x_new;//x0 наболее близки к х_new по сравнению с заданной xi,x_new>x0
    cout << "Input x_new to find y_new:";
    cin >> x_new;
    cout << "Input x0 and number of x0 in series:";
    cin >> x0;
    int index_x0;//положение x0 в заданной ряд x
    cin >> index_x0;
    index_x0 -= 1;
    float q = (x_new - x0) / h;//число шагов для достижения точки x0
    cout << "Value Y_new\n";
    double Px = y[index_x0];

    // Gauss 1 formula

    for (int i = 1; i <= n; i++)
    {
        Px += trlen_k_Gauss_1(q, i, delta, index_x0);
    }
    cout << "By Gauss 1 formula: " << Px<<endl;
    // Gauss 2 formula
    Px = y[index_x0];
    for (int i = 1; i <= n; i++)
    {
        Px += trlen_k_Gauss_2(q, i, delta, index_x0);
    }
    cout << "By Gauss 2 formula: " << Px;
    free(x);
    free(y);
}

int main() {
    solver();
    return 0;
}

