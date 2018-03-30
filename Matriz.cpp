#include <iostream>
#include <cmath>
#include "Matriz.hpp"
#include "Exceptions.hpp"

#define NOMEARQUIVO "Matriz.cpp"

using namespace std;

Matriz::Matriz() {
    linhas = -1;
    colunas = -1;
    matriz = NULL;
}

Matriz::Matriz(int linhas, int colunas) {
    if(linhas <= 0) {
        throw QuantidadeLinhasInvalidaException(__LINE__, NOMEARQUIVO);
    }
    if(colunas <= 0) {
        throw QuantidadeColunasInvalidaException(__LINE__, NOMEARQUIVO);
    }
    this->linhas = linhas;
    this->colunas = colunas;
    this->matriz = new long double*[this->linhas];
    for (int i = 0; i < this->linhas; i++) {
        this->matriz[i] = new long double[this->colunas];
    }
}

Matriz::Matriz(long double** matriz, int linhas, int colunas) {
    if(linhas <= 0) {
        throw QuantidadeLinhasInvalidaException(__LINE__, NOMEARQUIVO);
    }
    if(colunas <= 0) {
        throw QuantidadeColunasInvalidaException(__LINE__, NOMEARQUIVO);
    }
    atribuiMatriz(matriz, linhas, colunas);
}


long double Matriz::get(int i, int j) {
    testaValidadePosicao(i , j);
    return this->matriz[i][j];

}

void Matriz::set(int i, int j, long double valor) {
    testaValidadePosicao(i, j);
    this->matriz[i][j] = valor;
}

void Matriz::operator=(const Matriz& matriz) {
    if(matriz.linhas <= 0 || matriz.colunas <= 0) {
        throw MatrizNulaException(__LINE__, NOMEARQUIVO);
    }
    this->apagaMatriz();
    this->linhas = matriz.linhas;
    this->colunas = matriz.colunas;
    this->matriz = new long double*[this->linhas];
    for (int i = 0; i < this->linhas; i++) {
        this->matriz[i] = new long double[this->colunas];
    }
    for (int i = 0; i < this->linhas; i++) {
        for (int j = 0; j < this->colunas; j++) {
            this->matriz[i][j] = matriz.matriz[i][j];
        }
    }
}

Matriz Matriz::operator+(const Matriz& matriz) {
    this->testaValidadeMatriz();
    if(matriz.linhas <= 0 || matriz.colunas <= 0) {
        throw MatrizNulaException(__LINE__, NOMEARQUIVO);
    }
    if(this->linhas != matriz.linhas) {
        throw LinhasDiferentesException(__LINE__, NOMEARQUIVO);
    }
    if(this->colunas != matriz.colunas) {
        throw ColunasDiferentesException(__LINE__, NOMEARQUIVO);
    }
    Matriz resultado(this->linhas, this->colunas);
    for(int i = 0; i < this->linhas; i++) {
        for (int j = 0; j < this->colunas; j++) {
            resultado.set(i, j, this->matriz[i][j] + matriz.matriz[i][j]);
        }
    }
    return resultado;
}


void Matriz::operator+=(const Matriz& matriz) {
    this->testaValidadeMatriz();
    if(matriz.linhas <= 0 || matriz.colunas <= 0) {
        throw MatrizNulaException(__LINE__, NOMEARQUIVO);
    }
    if(this->linhas != matriz.linhas) {
        throw LinhasDiferentesException(__LINE__, NOMEARQUIVO);
    }
    if(this->colunas != matriz.colunas) {
        throw ColunasDiferentesException(__LINE__, NOMEARQUIVO);
    }
    for(int i = 0; i < this->linhas; i++) {
        for (int j = 0; j < this->colunas; j++) {
            this->matriz[i][j] = this->matriz[i][j] + matriz.matriz[i][j];
        }
    }
}

Matriz Matriz::operator-(const Matriz& matriz) {
    this->testaValidadeMatriz();
    if(matriz.linhas <= 0 || matriz.colunas <= 0) {
        throw MatrizNulaException(__LINE__, NOMEARQUIVO);
    }
    if(this->linhas != matriz.linhas) {
        throw LinhasDiferentesException(__LINE__, NOMEARQUIVO);
    }
    if(this->colunas != matriz.colunas) {
        throw ColunasDiferentesException(__LINE__, NOMEARQUIVO);
    }
    Matriz resultado(this->linhas, this->colunas);
    for(int i = 0; i < this->linhas; i++) {
        for (int j = 0; j < this->colunas; j++) {
            resultado.set(i, j, this->matriz[i][j] - matriz.matriz[i][j]);
        }
    }
    return resultado;
}

void Matriz::operator-=(const Matriz& matriz) {
    this->testaValidadeMatriz();
    if(matriz.linhas <= 0 || matriz.colunas <= 0) {
        throw MatrizNulaException(__LINE__, NOMEARQUIVO);
    }
    if(this->linhas != matriz.linhas) {
        throw LinhasDiferentesException(__LINE__, NOMEARQUIVO);
    }
    if(this->colunas != matriz.colunas) {
        throw ColunasDiferentesException(__LINE__, NOMEARQUIVO);
    }
    for(int i = 0; i < this->linhas; i++) {
        for (int j = 0; j < this->colunas; j++) {
            this->matriz[i][j] -= matriz.matriz[i][j];
        }
    }
}


Matriz Matriz::operator*(const long double& escalar) {
    this->testaValidadeMatriz();
    Matriz resultado(this->linhas, this->colunas);
    for(int i = 0; i < this->linhas; i++) {
        for (int j = 0; j < this->colunas; j++) {
            resultado.set(i, j, this->matriz[i][j] * escalar);
        }
    }
    return resultado;
}

Matriz operator*(const long double& escalar, const Matriz& matriz) {
    if(matriz.linhas <= 0 || matriz.colunas <= 0) {
        throw MatrizNulaException(__LINE__, NOMEARQUIVO);
    }
    Matriz resultado(matriz.linhas, matriz.colunas);
    for(int i = 0; i < matriz.linhas; i++) {
        for (int j = 0; j < matriz.colunas; j++) {
            resultado.set(i, j, matriz.matriz[i][j] * escalar);
        }
    }
    return resultado;
    
}

void Matriz::operator*=(const long double& escalar) {
    this->testaValidadeMatriz();
    for(int i = 0; i < this->linhas; i++) {
        for (int j = 0; j < this->colunas; j++) {
            this->matriz[i][j] = this->matriz[i][j] * escalar;
        }
    }
}


Matriz Matriz::operator*(const Matriz& matriz) {
    this->testaValidadeMatriz();
    if(matriz.linhas <= 0 || matriz.colunas <= 0) {
        throw MatrizNulaException(__LINE__, NOMEARQUIVO);
    }
    if(this->colunas != matriz.linhas) {
        throw MultiplicacaoIncompativelException(__LINE__, NOMEARQUIVO);
    }
    Matriz resultado(this->linhas, matriz.colunas);
    for(int i = 0; i < this->linhas; i++) {
        for (int j = 0; j < matriz.colunas; j++) {
            long double soma = 0;
            for (int k = 0; k < this->colunas; k++) {
                soma += this->matriz[i][k] * matriz.matriz[k][j];
            }
            resultado.set(i, j , soma);
        }
    }
    return resultado;
}

void Matriz::operator*=(const Matriz& matriz) {
    this->testaValidadeMatriz();
    if(matriz.linhas <= 0 || matriz.colunas <= 0) {
        throw MatrizNulaException(__LINE__, NOMEARQUIVO);
    }
    const Matriz resultado = (*this) * matriz;
    this->apagaMatriz();
    this->linhas = resultado.linhas;
    this->colunas = resultado.colunas;
    this->matriz = new long double*[this->linhas];
    for (int i = 0; i < this->linhas; i++) {
        this->matriz[i] = new long double[this->colunas];
    }
    for (int i = 0; i < this->linhas; i++) {
        for (int j = 0; j < this->colunas; j++) {
            this->matriz[i][j] = resultado.matriz[i][j];
        }
        
    }
}

Matriz Matriz::geraMatrizCofator(const int& posI, const int& posJ) {
    Matriz matrizCofator(this->linhas - 1, this->colunas - 1);
    for (int i = 0; i < this->linhas; i++) {
        for (int j = 0; j < this->colunas ; j++) {
            if(i < posI && j < posJ) {
                matrizCofator(i, j) = this->matriz[i][j];
            }
            if(i < posI && j > posJ) {
                matrizCofator(i, j - 1) = this->matriz[i][j];
            }
            if(i > posI && j < posJ) {
                matrizCofator(i - 1, j) = this->matriz[i][j];
            }
            if(i > posI && j > posJ) {
                matrizCofator(i - 1, j - 1) = this->matriz[i][j];
            }
        }
        
    }
    return matrizCofator;
}


long double Matriz::calculaDeterminante() {
    if(this->linhas == 1 || this->colunas == 1) {
        return this->matriz[0][0];
    }
    
    long double det = 0;
    int fila = 0;
    
    for (int i = 0; i < this->colunas; i++) {
        Matriz matrizCofator = this->geraMatrizCofator(fila, i);
        det += this->matriz[fila][i] * (pow(-1, fila + i + 2) * matrizCofator.calculaDeterminante());
    }
    return det;
}

long double Matriz::determinante() {
    this->testaValidadeMatriz();
    if(this->linhas != this->colunas) {
        throw LinhasDiferentesColunasException(__LINE__, NOMEARQUIVO);
    }
    return this->calculaDeterminante();
}


long double& Matriz::operator()(const int& i, const int& j) {
    testaValidadePosicao(i, j);
    return this->matriz[i][j];
}

void Matriz::atribuiMatriz(long double** matriz, int linhas, int colunas) {
    if(linhas <= 0) {
        throw QuantidadeLinhasInvalidaException(__LINE__, NOMEARQUIVO);
    }
    if(colunas <= 0) {
        throw QuantidadeColunasInvalidaException(__LINE__, NOMEARQUIVO);
    }
    this->apagaMatriz();
    this->linhas = linhas;
    this->colunas = colunas;
    this->matriz = new long double*[this->linhas];
    for (int i = 0; i < this->linhas; i++) {
        this->matriz[i] = new long double[this->colunas];
    }
    for (int i = 0; i < this->linhas; i++) {
        for (int j = 0; j < this->colunas; j++) {
            this->matriz[i][j] = matriz[i][j];
        }
    }
}


int Matriz::getLinhas() {
    return this->linhas;
}

int Matriz::getColunas() {
    return this->colunas;
}

void Matriz::testaValidadeMatriz() {
    if(this->linhas <= 0 || this->colunas <= 0) {
        throw MatrizNulaException(__LINE__, NOMEARQUIVO);
    }
}

void Matriz::testaValidadePosicao(const int& i, const int& j) {
    if(i < 0 || i >= this->linhas) {
        throw PosicaoLinhaInvalidaException(__LINE__, NOMEARQUIVO);
    }
    if(j < 0 || j >= this->colunas) {
        throw PosicaoColunaInvalidaException(__LINE__, NOMEARQUIVO);
    }
}

ostream& operator<<(ostream& os, const Matriz& matriz) {
    if(matriz.linhas <= 0 || matriz.colunas <= 0) {
        throw MatrizNulaException(__LINE__, NOMEARQUIVO);
    }
    for (int i = 0; i < matriz.linhas; i++) {
        for (int j = 0; j < matriz.colunas; j++) {
            os << matriz.matriz[i][j] << " ";
        }
        cout << endl;
    }
    
    return os;
}

istream& operator>>(istream& is, Matriz& matriz) {
    matriz.testaValidadeMatriz();
    for(int i = 0; i < matriz.linhas; i++) {
        for (int j = 0; j < matriz.colunas; j++) {
            is >> matriz.matriz[i][j];
        }
    }
    return is;
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


