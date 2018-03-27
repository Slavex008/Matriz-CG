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
		mat.imprimeMatriz();
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
		mat2.imprimeMatriz();
		//~ cout << " MAT 3 " << endl;
		//~ mat3.imprimeMatriz();
		cout << " MAT 3 = mat * mat2" << endl;
		mat3.imprimeMatriz();
	} catch (Exception ex) {
		cout << ex.getMessage();
	}
	
	return 0;
}
