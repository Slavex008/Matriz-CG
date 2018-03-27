#include "Matriz.hpp"
#include "Exceptions.hpp"

#include <iostream>

#define NOMEARQUIVO "Matriz.cpp"

using namespace std;

Matriz::Matriz(int linhas, int colunas) {
	if(linhas <= 0) {
		throw QuantidadeLinhasInvalidaException(__LINE__, NOMEARQUIVO);
	}
	if(colunas <= 0) {
		throw QuantidadeColunasInvalidaException(__LINE__, NOMEARQUIVO);
	}
	this->linhas = linhas;
	this->colunas = colunas;
	this->matriz = new double*[this->linhas];
	for (int i = 0; i < this->linhas; i++) {
		this->matriz[i] = new double[this->colunas];
	}
	for (int i = 0; i < this->linhas; i++) {
		for (int j = 0; j < this->colunas; j++)
		{
			this->matriz[i][j] = i + j;
		}
	}
}


double Matriz::get(int i, int j) {
	return this->matriz[i][j];

}
