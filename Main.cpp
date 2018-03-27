#include <iostream>
#include "Matriz.hpp"
#include "Exceptions.hpp"
using namespace std;

int main() {
	int linhas = -2;
	int colunas = 0;
	try {
		Matriz mat(linhas, colunas);
		for (int i = 0; i < linhas; i++) {
			for (int j = 0; j < colunas; j++) {
				cout << mat.get(i, j) << " ";
			}
			cout << endl;
		}
	} catch (QuantidadeLinhasInvalidaException ex) {
		cout << ex.getMessage();
	} catch (QuantidadeColunasInvalidaException ex) {
		cout << ex.getMessage();
	} 
	
	return 0;
}
