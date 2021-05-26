#include <iostream>
using namespace std;

void solve(){
    int n;
    do {
        cout << "Enter the maximum exponents of the polynomial : ";
        cin >> n;
    }while (n < 0);

    auto pA = new float[n + 1];
    auto pB = new float[n + 1];

    cout << "Enter the coefficients : " << endl;
    for (int i = 0; i <=n ; i++){
        cout << "a" << i << "=" << " ";
        cin >> pA[i];
    }

    int e;
    cout << "Divide (x - c); c =  "; cin >> e;
    pB[0] = pA[0];
    cout << "Result:" << pB[0] << "*" << "x^" << " " << (n - 1);
    for (int i = 1; i <= n ; i++){
        pB[i] = pA[i] + e * pB[i - 1];
        if (i <= n - 2){
            cout << "+" << pB[i] << "*x^" << n - i - 1;
        } else if (i == n-1) {
            cout << "+" << pB[i];
        } else {
            cout << "\nRemains: " << pB[i];
        }
    }

    float x;
    cout << "\nResult with x= ";
    cin >> x;
    float value1 = 0;
    float value2 = 0;
    for (int i = 0; i <= n; i++) value1 += pA[i] * pow(x,n-i);
    for (int i = 0; i <n; i++) value2 += pB[i] * pow(x, n - i - 1);
    value2 = value2 * (x - e) + pB[n];
    if(value1 == value2) cout<<"Result division :True";
    else cout << "Result division :False";
}


int main(){
    cout << "METHOD HORNER FOR DIVISION : " << endl;
    solve();
    return 0;
}