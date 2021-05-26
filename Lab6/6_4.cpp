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

void multiply(std::vector<base> &r,std::vector<base> &t,std::vector<base> &ans,int n){
    base *change;
    base q = 0;
    change = new base[n];
    for(int i=0; i<n; i++){
        for(int l=0; l<n; l++){
            for(int j=0; j<n; j++){
                change[j] = r[i* n + j]*t[j*n + l];
                q = q+change[j];
            }
            ans[i*n + l] = q/(base)n;
            q = 0;
        }
    }
}

void solver(){
    int N;
    cout << "Введите размерность матрицы: ";
    cin >> N;
    vector<base> a(N*N);
    vector<base> b(N*N);
    vector<base> c(N*N);
    for (int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            base tmp1(cos(-2*(i)*(j)*pi/N),sin(-2*(i)*(j)*pi/N));
            a[i*N + j] = tmp1;
            base tmp2(cos(-2*(i)*(j)*pi/N),-sin(-2*(i)*(j)*pi/N));
            b[i*N + j] = tmp2;
            cout << a[i*N + j] << "\t";
        }
        cout << endl;
    }
    multiply(a,b,c,N);
    cout << "ПРОВЕРКА" << endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) {
            cout << (complex<int>) c[i * N + j] << "\t";
        }
        cout << endl;
    }
}

int main(){
    solver();
    return 0;
}
