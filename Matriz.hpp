#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <iostream>

class Matriz {
    private:
        int linhas = -1;
        int colunas = -1;
        long double** matriz;
        
        void apagaMatriz();
        void testaValidadePosicao(const int& i, const int& j);
        
        long double calculaDeterminante();
        Matriz geraMatrizCofator(const int& posI, const int& posJ);
    public:
        Matriz();
        Matriz(long double** matriz, int linhas, int colunas);
        Matriz(int linhas, int colunas);
        
        int getLinhas();
        int getColunas();
        
        long double get(int i, int j);
        long double& operator()(const int& i, const int& j);
        
        void set(int i, int j, long double valor);
        
        Matriz operator+(const Matriz& matriz);
        Matriz operator-(const Matriz& matriz);
        Matriz operator*(const long double& escalar);
        Matriz operator*(const Matriz& matriz);
        
        void operator=(const Matriz& matriz);
        void operator+=(const Matriz& matriz);
        void operator-=(const Matriz& matriz);
        void operator*=(const long double& escalar);
        void operator*=(const Matriz& matriz);
        
        
        long double determinante();
        
        friend std::ostream& operator<<(std::ostream& os, const Matriz&);
        friend std::istream& operator>> (std::istream& is, Matriz& matriz);
        
        void atribuiMatriz(long double** matriz, int linhas, int colunas);
        ~Matriz();
    
};



#endif
