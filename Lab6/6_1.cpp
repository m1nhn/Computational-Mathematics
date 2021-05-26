/*
 * Author : Nguyen Le Minh
 * Group : N3251
 * Laboratory : 6
 */

#include <iostream>
using namespace std;

void solver(){
    int N = 0;
    cout << "Enter the size of the matrix : ";
    cin >> N;
    if (N != 3){
        cout << "Invalid size !!!" << endl;
        exit(1);
    }
    auto** arr = new double* [N];
    auto** tmparr = new double* [N];
    auto** minor = new double* [N - 1];
    for (int i = 0; i < N - 1; i++)
        minor[i] = new double[N - 1];
    auto* cords = new double[N]();
    for (int i = 0; i < N; i++) {
        arr[i] = new double[N]();
        tmparr[i] = new double[N]();
        for (int j = 0; j < N; j++) {
            cout << "Enter [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
            tmparr[i][j] = arr[i][j];
        }
    }
    int ki1, ki2, kj1, kj2;
    cout << "columns (1) or rows (0)? " << endl;
    int ans;
    cin >> ans;
    if (ans == 1) {
        cout << "Enter first and second vectors separated by space " << endl;
        cin >> kj1 >> kj2;
        if ((kj1 > 2) || (kj1 < 0) || (kj2 > 2) || (kj2 < 0)){
            cout << "You are trying to input a non-existent vector !" << endl;
            exit(1);
        }
        cords[0] = arr[1][kj1] * arr[2][kj2] - arr[1][kj2] * arr[2][kj1];
        cords[1] = -1 * (arr[0][kj1] * arr[2][kj2] - arr[0][kj2] * arr[2][kj1]);
        cords[2] = arr[0][kj1] * arr[1][kj2] - arr[0][kj2] * arr[1][kj1];
        double scal = 0;
        for (int i = 0; i < 3; i++)
            scal += arr[i][kj1] * arr[i][kj2];
        cout << "Vector product: " << std::endl;
        cout << cords[0] << "*i + " << cords[1] << "*j + " << cords[2] << "*k\n";
        cout << "Scalar product:  " << scal;
    }
    else if (ans == 0) {
        cout << "Enter first and second vectors separated by space" << std::endl;
        cin >> ki1 >> ki2;
        if ((ki1 > 2) || (ki1 < 0) || (ki2 > 2) || (ki2 < 0)){
            cout << "You are trying to throw invalid inputs !!!" << endl;
            exit(1);
        }
        cords[0] = arr[ki1][1] * arr[ki2][2] - arr[ki2][1] * arr[ki1][2];
        cords[1] = -1 * (arr[ki1][0] * arr[ki2][2] - arr[ki2][0] * arr[ki1][2]);
        cords[2] = arr[ki1][0] * arr[ki2][1] - arr[ki2][0] * arr[ki1][1];
        double scal = 0;
        for (int i = 0; i < 3; i++)
            scal += arr[ki1][i] * arr[ki2][i];
        cout << "Vector product :" << endl;
        cout << cords[0] << "*i + " << cords[1] << "*j + " << cords[2] << "*k" << endl;
        cout << "Scalar product " << scal;
    }
    else {
        cout << "No output can be imagined !" << endl;
        exit(1);
    }
    for(int i = 0; i < N; i++)
        delete [] arr[i], tmparr[i], minor[i];
    delete [] arr, tmparr, minor, cords;
}

int main() {
    solver();
    return 0;
}
