#ifndef MATRIZ_HPP
#define MATRIZ_HPP

class Matriz {
	private:
		int linhas;
		int colunas;
		double** matriz;
		
	public:
		Matriz(int linhas, int colunas);
		double get(int i, int j);
	
};



#endif
