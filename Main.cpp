#include <iostream>
#include "Matriz.hpp"
#include "Exceptions.hpp"
using namespace std;

int main() {
	int linhas = 2;
	int colunas = 3;
	try {
		Matriz mat(linhas, colunas);
		for (int i = 0; i < linhas; i++) {
			for (int j = 0; j < colunas; j++) {
				mat.set(i, j, i + j);
			}
		}
		mat.imprimeMatriz();
		cout << endl << endl;
		linhas = 4;
		colunas = 7;
		double** mat2 = new double*[linhas];
		for (int i = 0; i < linhas; i++) {
			mat2[i] = new double[colunas];
		}
		for (int i = 0; i < linhas; i++) {
			for (int j = 0; j < colunas; j++) {
				mat2[i][j] = i + j;
				cout << mat2[i][j] << " ";
			}
			cout << endl;
		}
		
		cout << endl << endl;
		mat.atribuiMatriz(mat2, linhas, colunas);
		mat.imprimeMatriz();
	} catch (Exception ex) {
		cout << ex.getMessage();
	}
	
	return 0;
}
