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
