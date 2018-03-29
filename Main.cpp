#include <iostream>
#include "Matriz.hpp"
#include "Exceptions.hpp"
using namespace std;

int main() {
    int linhas = 3;
    int colunas = 3;
    try {
        Matriz mat(linhas, colunas);
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                mat.set(i, j, i + j);
            }
        }
        cout << " MAT " << endl;
        cout << mat << endl;
        Matriz mat2(linhas, colunas);
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                mat2.set(i, j, i * j);
            }
        }
        //~ cout << " MAT 2 " << endl;
        //~ mat2.imprimeMatriz();
        Matriz mat3 = mat * mat2;
        cout << endl;
        //~ cout << " MAT 1 " << endl;
        //~ mat.imprimeMatriz();
        cout << " MAT 2 " << endl;
        cout << mat2 << endl;
        //~ cout << " MAT 3 " << endl;
        //~ mat3.imprimeMatriz();
        cout << " MAT 3 = mat * mat2" << endl;
        cout << mat3 << endl;
        double a = mat3(2, 2);
        a = 43;
        cout << a << " " << mat3(2, 2) << endl; 
        Matriz teste;
        mat *= 10;
        cout << " MAT = mat * mat2" << endl;
        cout << mat3 << endl;
        Matriz mat4(linhas, colunas);
        cin >> mat4;
        cout << mat4;
    } catch (Exception ex) {
        cout << ex.getMessage();
    }
    
    return 0;
}
