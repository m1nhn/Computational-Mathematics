/*
 * Author : Nguyen Le Minh
 * Group : N3251
 * Lab : 6
 */
#include <iostream>
#include <complex>
#include <cmath>
#include <vector>
using namespace std;

typedef complex<double> base;

#define pi 3.14159265358979323846

void multiply(vector<base> &r,vector<base> &t,vector<base> &ans,int n){
    base change;
    base q = 0;
    for(int l=0; l<n; l++){
        for(int j=0; j<n; j++){
            change = r[l*n + j]*t[j];
            q = q+change;
        }
        ans[l] = q/(base)n;
        q = 0;
    }
}

void solver(){
    int N, koef;
    label:
    cout << "Введите 1 для прямого преобразования или -1 для обратного: ";
    cin >> koef;
    if(koef != 1 && koef != -1)
        goto label;
    cout << "Введите количество элементов (1,2,4,8...): ";
    cin >> N;
    vector<base> a(N*N);
    vector<base> arr(N);
    vector<base> ans(N);
    cout << "Введите вектор комплексный типа (a,b): " << endl;
    for (int i = 0; i < N; i++){
        cout << "Введите элемент arr[" << i << "]: ";
        cin >> arr[i];
        for(int j = 0; j < N; j++){
            base tmp(cos(-2*(i)*(j)*pi/N*koef),sin(-2*(i)*(j)*pi/N*koef));
            a[i*N + j] = tmp;
        }
    }
    multiply(a, arr, ans, N);
    for(int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }
}

int main(){
    solver();
    return 0;
}
