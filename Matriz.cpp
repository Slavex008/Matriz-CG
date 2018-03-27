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
}

Matriz::Matriz(double** matriz, int linhas, int colunas) {
	if(linhas <= 0) {
		throw QuantidadeLinhasInvalidaException(__LINE__, NOMEARQUIVO);
	}
	if(colunas <= 0) {
		throw QuantidadeColunasInvalidaException(__LINE__, NOMEARQUIVO);
	}
	atribuiMatriz(matriz, linhas, colunas);
}


double Matriz::get(int i, int j) {
	if(i < 0 || i >= this->linhas) {
		throw PosicaoLinhaInvalidaException(__LINE__, NOMEARQUIVO);
	}
	if(j < 0 || j >= this->colunas) {
		throw PosicaoColunaInvalidaException(__LINE__, NOMEARQUIVO);
	}
	return this->matriz[i][j];

}

void Matriz::set(int i, int j, double valor) {
	if(i < 0 || i >= this->linhas) {
		throw PosicaoLinhaInvalidaException(__LINE__, NOMEARQUIVO);
	}
	if(j < 0 || j >= this->colunas) {
		throw PosicaoColunaInvalidaException(__LINE__, NOMEARQUIVO);
	}
	this->matriz[i][j] = valor;
}

void Matriz::operator=(Matriz &matriz) {
	if(matriz.getLinhas() <= 0 || matriz.getColunas() <= 0) {
		throw MatrizInvalidaException(__LINE__, NOMEARQUIVO);
	}
	this->apagaMatriz();
	this->linhas = matriz.getLinhas();
	this->colunas = matriz.getColunas();
	this->matriz = new double*[this->linhas];
	for (int i = 0; i < this->linhas; i++) {
		this->matriz[i] = new double[this->colunas];
	}
	for (int i = 0; i < this->linhas; i++) {
		for (int j = 0; j < this->colunas; j++) {
			this->matriz[i][j] = matriz.get(i, j);
		}
	}
}

void Matriz::atribuiMatriz(double** matriz, int linhas, int colunas) {
	if(linhas <= 0) {
		throw QuantidadeLinhasInvalidaException(__LINE__, NOMEARQUIVO);
	}
	if(colunas <= 0) {
		throw QuantidadeColunasInvalidaException(__LINE__, NOMEARQUIVO);
	}
	this->apagaMatriz();
	this->linhas = linhas;
	this->colunas = colunas;
	this->matriz = new double*[this->linhas];
	for (int i = 0; i < this->linhas; i++) {
		this->matriz[i] = new double[this->colunas];
	}
	for (int i = 0; i < this->linhas; i++) {
		for (int j = 0; j < this->colunas; j++) {
			this->matriz[i][j] = matriz[i][j];
		}
	}
}


void Matriz::imprimeMatriz() {
	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			cout << this->matriz[i][j] << " ";
		}
		cout << endl;
	}
}

int Matriz::getLinhas() {
	return this->linhas;
}

int Matriz::getColunas() {
	return this->colunas;
}


void Matriz::apagaMatriz() {
	if(linhas > 0 || colunas > 0) {
		for (int i = 0; i < linhas; i++) {
			delete[] matriz[i];
		}
		delete[] matriz;
	}
	linhas = -1;
	colunas = -1;
}

Matriz::~Matriz() {
	this->apagaMatriz();
}

