#include "Matriz.hpp"
#include "Exceptions.hpp"
#include <iostream>

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
    testaValidadePosicao(i , j);
    return this->matriz[i][j];

}

void Matriz::set(int i, int j, double valor) {
    testaValidadePosicao(i, j);
    this->matriz[i][j] = valor;
}

void Matriz::operator=(const Matriz& matriz) {
    if(matriz.linhas <= 0 || matriz.linhas <= 0) {
        throw MatrizInvalidaException(__LINE__, NOMEARQUIVO);
    }
    this->apagaMatriz();
    this->linhas = matriz.linhas;
    this->colunas = matriz.colunas;
    this->matriz = new double*[this->linhas];
    for (int i = 0; i < this->linhas; i++) {
        this->matriz[i] = new double[this->colunas];
    }
    for (int i = 0; i < this->linhas; i++) {
        for (int j = 0; j < this->colunas; j++) {
            this->matriz[i][j] = matriz.matriz[i][j];
        }
    }
}

Matriz Matriz::operator+(const Matriz& matriz) {
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


Matriz Matriz::operator*(const double& escalar) {
    Matriz resultado(this->linhas, this->colunas);
    for(int i = 0; i < this->linhas; i++) {
        for (int j = 0; j < this->colunas; j++) {
            resultado.set(i, j, this->matriz[i][j] * escalar);
        }
    }
    return resultado;
}

void Matriz::operator*=(const double& escalar) {
    for(int i = 0; i < this->linhas; i++) {
        for (int j = 0; j < this->colunas; j++) {
            this->matriz[i][j] = this->matriz[i][j] * escalar;
        }
    }
}


Matriz Matriz::operator*(const Matriz& matriz) {
    if(this->colunas != matriz.linhas) {
        throw MultiplicacaoIncompativelException(__LINE__, NOMEARQUIVO);
    }
    Matriz resultado(this->linhas, matriz.colunas);
    for(int i = 0; i < this->linhas; i++) {
        for (int j = 0; j < matriz.colunas; j++) {
            double soma = 0;
            for (int k = 0; k < this->colunas; k++) {
                soma += this->matriz[i][k] * matriz.matriz[k][j];
            }
            resultado.set(i, j , soma);
        }
    }
    return resultado;
}

void Matriz::operator*=(const Matriz& matriz) {
    const Matriz resultado = (*this) * matriz;
    this->apagaMatriz();
    this->linhas = resultado.linhas;
    this->colunas = resultado.colunas;
    this->matriz = new double*[this->linhas];
    for (int i = 0; i < this->linhas; i++) {
        this->matriz[i] = new double[this->colunas];
    }
    for (int i = 0; i < this->linhas; i++) {
        for (int j = 0; j < this->colunas; j++) {
            this->matriz[i][j] = resultado.matriz[i][j];
        }
        
    }
}


double& Matriz::operator()(const int& i, const int& j) {
    testaValidadePosicao(i, j);
    return this->matriz[i][j];
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


int Matriz::getLinhas() {
    return this->linhas;
}

int Matriz::getColunas() {
    return this->colunas;
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
    if(matriz.linhas <= 0 || matriz.colunas <= 0) {
        throw MatrizNulaException(__LINE__, NOMEARQUIVO);
    }
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


