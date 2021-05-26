#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    // Считываем размер вводимой матрицы
    int size;
    cout << "Введите кол-во уравнений: \n";
    cin >> size;
    // Будем хранить матрицу в векторе, состоящем из
    // векторов вещественных чисел
    vector <vector <long double> > matrix;
    // Матрица будет иметь размер (size) x (size + 1),
    // c учетом столбца свободных членов
    matrix.resize(size);
    cout << "Введите матрицу поэлементно\n";
    for (int i = 0; i < size; i++){
        matrix[i].resize(size + 1);
        for (int j = 0; j < size + 1; j++){
            std::cout << "a[" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }
    cout << "Введите точность\n";
    // Считываем необходимую точность решения
    long double eps;
    cin >> eps;
    // Введем вектор значений неизвестных на предыдущей итерации,
    // размер которого равен числу строк в матрице, т.е. size,
    // причем согласно методу изначально заполняем его нулями
    vector <long double> previousVariableValues(size, 0.0);
    // Будем выполнять итерационный процесс до тех пор,
    // пока не будет достигнута необходимая точность
    while (true){
        // Введем вектор значений неизвестных на текущем шаге
        vector <long double> currentVariableValues(size);
        // Посчитаем значения неизвестных на текущей итерации
        // в соответствии с теоретическими формулами
        for (int i = 0; i < size; i++){
            // Инициализируем i-ую неизвестную значением
            // свободного члена i-ой строки матрицы
            currentVariableValues[i] = matrix[i][size];
            // Вычитаем сумму по всем отличным от i-ой неизвестным
            for (int j = 0; j < size; j++){
                // При j < i можем использовать уже посчитанные
                // на этой итерации значения неизвестных
                if (j < i)
                    currentVariableValues[i] -= matrix[i][j] * currentVariableValues[j];
                // При j > i используем значения с прошлой итерации
                if (j > i)
                    currentVariableValues[i] -= matrix[i][j] * previousVariableValues[j];
            }
            // Делим на коэффициент при i-ой неизвестной
            currentVariableValues[i] /= matrix[i][i];
        }
        // Посчитаем текущую погрешность относительно предыдущей итерации
        long double error = 0.0;
        for (int i = 0; i < size; i++)
            error += abs(currentVariableValues[i] - previousVariableValues[i]);

        // Если необходимая точность достигнута, то завершаем процесс
        if (error < eps)
            break;
        // Переходим к следующей итерации, так
        // что текущие значения неизвестных
        // становятся значениями на предыдущей итерации
        previousVariableValues = currentVariableValues;
    }

    // Выводим найденные значения неизвестных с 8 знаками точности
    for (int i = 0; i < size; i++)
        printf("x[%d]: %.8llf ", i, previousVariableValues[i]);
    return 0;
}
