#include <iostream>
using namespace std;

int main(){
    double rel_error_x, rel_error_y, abs_er_x = 0.5, abs_er_y = 0.1, x = 9, y = 7.5;
    cout << "x = " << x << " y = " << y<<"\n";
    rel_error_x = abs_er_x / x;
    rel_error_y = abs_er_y / y;
    cout << "x absError = " << abs_er_x << "\n";
    cout << "y absError = " << abs_er_y << "\n";
    cout << "x relError = " << rel_error_x << "\n";
    cout << "y relError = " << rel_error_y << "\n";
    cout << "Sum: 1\nDifferent: 2\nMultiplication: 3\nDivision: 4\n";
    int checker = 1;
    std::cin >> checker;
    switch (checker) {
        case(1):
            cout << "x + y = " << x + y << "\n";
            cout << "x + y absError = " << abs_er_x + abs_er_y << "\n";
            cout << "x + y relError = " << (abs_er_x + abs_er_y) / (x + y) << "\n";
            break;
        case(2):

            cout << "x - y = " << x - y << "\n";
            cout << "x - y absError = " << abs_er_x + abs_er_y << "\n";
            cout << "x - y relError = " << (abs_er_x + abs_er_y) / (x - y) << "\n";
            break;
        case(3):
            cout << "x * y = " << x * y << "\n";
            cout << "x * y absError = " << (rel_error_x + rel_error_y) * x * y << "\n";
            cout << "x * y relError = " << rel_error_x + rel_error_y << "\n";
            break;
        case(4):
            cout << "x * y = " << x / y << "\n";
            cout << "x * y absError = " << (rel_error_x + rel_error_y) * x / y << "\n";
            cout << "x * y relError = " << rel_error_x + rel_error_y << "\n";
            break;
    }
    return 0;
}
