/*
 * Author : Nguyen Le Minh
 * Group : N3251
 * Lab : 6
 */

#include <iostream>
using namespace std;

void show(float **a,int n);
void fill(float **a,int n);
void fill_t(float **a,int n);
float scalyar(float **a,float **b,int col1,int col2,int n);
void ort(float **a,float **r,float **t,int n);
void multiply(float **r,float **t,float **ans,int n);
void get_r_mat(float **a,float **r,float **t,int col,int n);

void solver(){
    float **a,**r,**t,**ans;
    int n;
    cout << "Введите размерность матрицы: ";
    cin >> n;
    a = new float*[n];
    r = new float*[n];
    t = new float*[n];
    ans = new float*[n];
    for(int i=0; i<n; i++){
        a[i] = new float[n];
        r[i] = new float[n];
        t[i] = new float[n];
        ans[i] = new float[n];
    }
    fill(a,n);
    cout << "MATRIX A" << endl;
    show(a,n);
    for(int i=0; i<n; i++){
        for(int j=0;j<n;j++)
            r[i][j] = 0;
        r[i][0] = a[i][0];
    }
    cout << "MATRIX R" << endl;
    show(r,n);
    fill_t(t,n);
    cout << "MATRIX T" << endl;
    show(t,n);
    ort(a,r,t,n);
    cout << "ОРТОГОНАЛЬНЫЕ" << endl;
    cout << "MATRIX A" << endl;
    show(a,n);
    cout << "MATRIX R" << endl;
    show(r,n);
    cout << "MATRIX T" << endl;
    show(t,n);
    multiply(r,t,ans,n);
    cout << "ПРОВЕРКА" << endl;
    cout << "MATRIX R*T" << endl;
    show(ans,n);
}

int main(){
    solver();
    return 0;
}

void show(float **a,int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

void fill(float **a,int n){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cout << "Введите a[" << i << "][" << j <<"]: ";
            cin >> a[i][j];
        }
}

void fill_t(float **a,int n){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            a[i][j] = 0;
    for(int i=0; i<n; i++)
        a[i][i] = 1;
}

float scalyar(float **a,float **b,int col1,int col2,int n){
    float q = 0;
    for(int i=0; i<n; i++)
        q = q+(a[i][col1]*b[i][col2]);
    return q;
}

void ort(float **a,float **r,float **t,int n){
    float s1 = 0;
    float s2 = 0;
    int c = 1;
    for(int i=0; i<n; i++){
        if(i>0)
            get_r_mat(a,r,t,i,n);
        for(int j=c; j<n; j++){
            s1 = scalyar(a,r,j,i,n);
            s2 = scalyar(r,r,i,i,n);
            t[i][j] = s1/s2;
        }
        c = c+1;
    }
}

void multiply(float **r,float **t,float **ans,int n){
    float *change;
    float q = 0;
    change = new float[n];
    for(int i=0; i<n; i++){
        for(int l=0; l<n; l++){
            for(int j=0; j<n; j++){
                change[j] = r[i][j]*t[j][l];
                q = q+change[j];
            }
            ans[i][l] = q;
            q = 0;
        }
    }
}

void get_r_mat(float **a,float **r,float **t,int col,int n){
    for (int i=0;i<n;i++){
        for(int  j=0;j<col;j++)
            r[i][col]+=t[j][col]*r[i][j];
        r[i][col]=a[i][col]-r[i][col];
    }
}
