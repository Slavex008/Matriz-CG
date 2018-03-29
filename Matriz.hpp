#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <iostream>

class Matriz {
    private:
        int linhas = -1;
        int colunas = -1;
        double** matriz;
        void apagaMatriz();
        void testaValidadePosicao(const int& i, const int& j);
    public:
        Matriz();
        Matriz(double** matriz, int linhas, int colunas);
        Matriz(int linhas, int colunas);
        
        int getLinhas();
        int getColunas();
        
        double get(int i, int j);
        double& operator()(const int& i, const int& j);
        void set(int i, int j, double valor);
        
        Matriz operator+(const Matriz& matriz);
        Matriz operator-(const Matriz& matriz);
        Matriz operator*(const double& escalar);
        Matriz operator*(const Matriz& matriz);
        
        void operator=(const Matriz& matriz);
        void operator+=(const Matriz& matriz);
        void operator-=(const Matriz& matriz);
        void operator*=(const double& escalar);
        void operator*=(const Matriz& matriz);
        
        
        friend std::ostream& operator<<(std::ostream& os, const Matriz&);
        friend std::istream& operator>> (std::istream& is, Matriz& matriz);
        
        void atribuiMatriz(double** matriz, int linhas, int colunas);
        ~Matriz();
    
};



#endif
