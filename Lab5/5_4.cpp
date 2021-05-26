/*
 * Author : Nguyen Le Minh
 * Group : N3251
 * Laboratory : 5
 */
#include <iostream>
using namespace std;

class Matr{
private:
    int maxCounts = 20000;
    int n{};
    double **masA;
    double *masB;
public:
    // constructor, requires input of dimension,
    // matrices of coefficients of equations and
    // matrices of free members
    Matr(){
        cout << "Enter the dimension:  ";
        cin >> n;
        masB = new double[n];
        masA = new double*[n];
        for(int i = 0; i < n; i++){
            masA[i] = new double[n];
            for(int j = 0; j < n; j++){
                cout << "Please enter a[" << i << "][" << j << "]: ";
                cin >> masA[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            cout << "Please enter b[" << i << "]: ";
            cin >> masB[i];
        }
    }
    // the destructor cleans up memory from
    // matrices of free members
    // and matrices of coefficients of equations
    ~Matr(){
        for(int i = 0; i < n; i++)
            delete [] masA[i];
        delete [] masA, masB;
    }
    // iteration method for solving the СЛАУ
    void Itera(){
        auto *currentVariableValues = new double[n];
        auto *previousVariableValues = new double[n]();
        int counter = 0;
        do{
            // Calculate the values of the unknowns at the current iteration
            // according to theoretical formulas
            for (int i = 0; i < n; i++){
                // Initialize the i-th unknown value
                // free member of the i-th row of the matrix
                currentVariableValues[i] = masB[i];
                // Subtract the sum for all unknowns different from the i-th
                for (int j = 0; j < n; j++)
                    if (i != j)
                        currentVariableValues[i] -= masA[i][j] * previousVariableValues[j];
                // Divide by the coefficient for the i-th unknown
                currentVariableValues[i] /= masA[i][i];
            }
            previousVariableValues = currentVariableValues;
            counter++;
        }while (counter < maxCounts);
        for (int i = 0; i < n; i++)
            cout << "x[" << i << "] = " << previousVariableValues[i] << endl;
        delete [] currentVariableValues, previousVariableValues;
    }
};

void solver(){
    Matr *res = new Matr;
    res->Itera();
    delete res;
}

int main(){
    solver();
    return 0;
}
