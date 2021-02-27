#include <iostream>
#include <iomanip>
using namespace std;

int** new2DArray(const int m, const int n)
{
    int** arr = new int*[m];
    for (int i = 0; i < m; ++i)
        arr[i] = new int[n];
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            cout << "a[" << i << "][" << j << "]:";
            cin >> arr[i][j];
        }
    return arr;
}

void print2DArray(int** arr, const int m, const int n)
{
    for (int i = 0; i < m; ++i)
    {
        cout << "|";
        for (int j = 0; j < n; ++j)
            cout << std::setw(8) << arr[i][j];
        cout << "|\n";
    }
}

void delete2DArray(int** arr, const int m)
{
    for (int i = 0; i < m; ++i)
        delete[] arr[i];
    delete[] arr;
}
void sumMinusMatrix(int** mA, int** mB,
                    const int m, const int n) {
    int** mSum = new int*[m];
    int** mMinus = new int*[m];
    for (int i = 0; i < m; ++i){
        mSum[i] = new int[n];
        mMinus[i] = new int[n];
    }

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            mSum[i][j] = mA[i][j] + mB[i][j];
            mMinus[i][j] = mA[i][j] - mB[i][j];
        }
    cout << "A plus B:\n";
    print2DArray(mSum, m, n);
    cout << "A subtracts B :\n";
    print2DArray(mMinus, m, n);
    delete2DArray(mSum, m);
    delete2DArray(mMinus,m);
}
void mulNumMatrix(int** mA, const int m, const int n,const int num) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            mA[i][j] *= num;
        }
    }
    print2DArray(mA, m, n);
}

void matrixMul(int** mA, int** mB, const int m, const int n){
    if (m != n){
        cout << "Matrix A can not multiplies matrix B" << endl;
        return;
    }
    int** mMul = new int*[m];
    for (int i = 0; i < m; ++i){
        mMul[i] = new int[n];
        for (int j = 0; j < n; ++j){
            mMul[i][j] = 0;
            for (int k = 0; k < n; ++k){
                mMul[i][j] += mA[i][k] * mB[k][j];
            }
            }
        }
    print2DArray(mMul,m,n);
    delete2DArray(mMul,m);
}
int main()
{
    // вводим размеры матрицы
    cout << "Input m: ";
    int m;
    cin >> m;

    cout << "Input n: ";
    int n;
    cin >> n;

    cout << "Input matrix A!" << endl;
    int** mtrxA = new2DArray(m, n);
    cout << "Input matrix B!" << endl;
    int** mtrxB = new2DArray(m, n);
    print2DArray(mtrxA,m,n);
    print2DArray(mtrxB,m,n);
    cout << "Sum and Difference between matrix A and B" << endl;
    sumMinusMatrix(mtrxA, mtrxB, m, n);

    cout << "Result matrix A multiply with matrix B:\n";
    matrixMul(mtrxA,mtrxB,m,n);

    int num;
    cout << "Matrix A multiply with number:";
    cin >> num;
    cout << "Result matrix A multiply with number:\n";
    mulNumMatrix(mtrxA,m,n,num);


    // освобождаем выделенную память
    delete2DArray(mtrxA, m);
    delete2DArray(mtrxB, m);
    return 0;
}
