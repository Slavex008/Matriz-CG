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
        cout << " MAT2 " << endl;
        cout << mat2 << endl;
        cout << "SOMA" << endl;
        cout << mat + mat2 << endl;
        cout << "SUBTRACAO" << endl;
        cout << mat - mat2 << endl;
        cout << "MULTIPLICACAO MAT x10" << endl;
        cout << 10 * mat << endl;
        cout << "MULTIPLICACAO" << endl;
        cout << mat * mat2 << endl;
        cout << "DETERMINANTE MAT" << endl;
        cout << mat.determinante() << endl;
        
        cout << "---------------------------" << endl;
        cin >> linhas >> colunas;
        Matriz mat4(linhas, colunas);
        cin >> mat4;
        cout << mat4.determinante() << endl;
        
    } catch (Exception ex) {
        cout << ex.getMessage();
    }
    
    return 0;
}
