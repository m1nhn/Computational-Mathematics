/*
 * Author : Nguyen Le Minh
 * Group : N3251
 * Laboratory : 5
 */
#include <iostream>
using namespace std;

void j_swap(double** arr, int N, int li, int lj){
    for (int i = 0; i < N; i++){
        double tmp = arr[i][lj];
        arr[i][lj] = arr[i][li];
        arr[i][li] = tmp;
    }
}

void i_swap(double** arr, int N, int li, int lj){
    for (int j = 0; j < N; j++){
        double tmp = arr[lj][j];
        arr[lj][j] = arr[li][j];
        arr[li][j] = tmp;
    }
}

double det(double **arr, int N){
    int i, j, k = 0, swaps = 0;
    bool checker = true;
    double det = 1;
    while (k < N * N && checker) {
        checker = false;
        for (i = 0; i < N; i++)
            if (arr[i][i] == 0) {
                if (k / N % 2 == 0)
                    j_swap(arr, N, k % N, i);
                else
                    i_swap(arr, N, k % N, i);
                if (k % N != i) swaps++;
                k++;
                checker = true;
                break;
            }
    }
    if(k == N * N && checker) {
        return 0;
    }
    if (swaps % 2 == 1) {
        det *= -1;
    }
    for (i = 0; i < N; i++) {
        for (k = i + 1; k < N; k++)
            for (j = N - 1; j >= i; j--)
                arr[j][k] = arr[j][k] - arr[j][i] / arr[i][i] * arr[i][k];
        det = arr[i][i] * det;
    }
    return det;
}

int main(){
    int i, j, N = 0;
    cout << "Enter the number of unknowns";
    cin >> N;
    auto** arr = new double* [N];
    auto** tmparr = new double* [N];
    auto* dets = new double[N]();
    for (i = 0; i < N; i++) {
        arr[i] = new double[N];
        tmparr[i] = new double[N];
        for (j = 0; j < N; j++) {
            cout << "Please enter arr[" << i << "][" << j << "]: ";
            cin >> arr[i][j];
            tmparr[i][j] = arr[i][j];
        }
    }
    cout << "Enter the matrix " << endl;
    auto* B = new double[N]();
    for (i = 0; i < N; i++){
        cout << "B[" << i << "]:";
        cin >> B[i];
    }
    double detA = det(tmparr, N);
    if (detA == 0) {
        cout << "The determinant is zero! " << endl;
        return 1;
    }
    for (i = 0; i < N; i++){
        for (int b = 0; b < N; b++)
            for (int k = 0; k < N; k++)
                tmparr[b][k] = arr[b][k];
        for (int k = 0; k < N; k++)
            tmparr[k][i] = B[k];
        dets[i] = det(tmparr, N);
    }
    cout << "Determinant of the matrix of coefficients of the system: " << detA << endl;
    cout << "Roots are " << endl;
    for (i = 0; i < N; i++){
        cout << "det[" << i << "] " << dets[i]<< endl;
        cout << "x[" << i << "] = " << dets[i] / detA << endl;
    }
    for(i = 0; i < N; i++){
        delete [] arr[i], tmparr[i];
    }
    delete [] arr, tmparr, dets;
    return 0;
}
