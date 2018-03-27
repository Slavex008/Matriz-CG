#include "Exceptions.hpp"

using namespace std;

inline Exception::Exception(int linha, string nome, string descricao) {
	this->message = "Erro na linha " + to_string(linha) + " no arquivo " + nome + "!\n";
	this->message += descricao + "\n\n";
}


inline string Exception::getMessage() {
	return this->message;
}

QuantidadeLinhasInvalidaException::QuantidadeLinhasInvalidaException(int linha, string nome) : 
			Exception::Exception(linha, nome, "A quantidade de colunas deve ser maior que 0!") {}

string QuantidadeLinhasInvalidaException::getMessage() {
	return Exception::getMessage();
}

QuantidadeColunasInvalidaException::QuantidadeColunasInvalidaException(int linha, string nome) :
			Exception::Exception(linha, nome, "A quantidade de colunas deve ser maior que 0!") {}

string QuantidadeColunasInvalidaException::getMessage() {
	return Exception::getMessage();
}

PosicaoLinhaInvalidaException::PosicaoLinhaInvalidaException(int linha, string nome) :
			Exception::Exception(linha, nome, "Posição de linha inválida!") {}

string PosicaoLinhaInvalidaException::getMessage() {
	return Exception::getMessage();
}

PosicaoColunaInvalidaException::PosicaoColunaInvalidaException(int linha, string nome) :
			Exception::Exception(linha, nome, "Posição de coluna inválida!") {}

string PosicaoColunaInvalidaException::getMessage() {
	return Exception::getMessage();
}

MatrizInvalidaException::MatrizInvalidaException(int linha, string nome) :
			Exception::Exception(linha, nome, "Matriz inválida: quantidade de linhas ou colunas inválidos!") {}

string MatrizInvalidaException::getMessage() {
	return Exception::getMessage();
}
