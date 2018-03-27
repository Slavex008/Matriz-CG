#ifndef MATRIZ_HPP
#define MATRIZ_HPP

class Matriz {
	private:
		int linhas = -1;
		int colunas = -1;
		double** matriz;
		void apagaMatriz();
	public:
		Matriz(double** matriz, int linhas, int colunas);
		Matriz(int linhas, int colunas);
		
		double get(int i, int j);
		int getLinhas();
		int getColunas();
		void set(int i, int j, double valor);
		
		void operator=(Matriz &matriz);
		void atribuiMatriz(double** matriz, int linhas, int colunas);
		
		void imprimeMatriz();
		~Matriz();
	
};



#endif
