#include "Exceptions.hpp"

using namespace std;

QuantidadeLinhasInvalidaException::QuantidadeLinhasInvalidaException(int linha, string nome) {
	this->message = "Erro na linha " + to_string(linha) + " no arquivo " + nome + "!\n";
	this->message += "A quantidade de linhas deve ser maior que 0\n\n";
}

string QuantidadeLinhasInvalidaException::getMessage() {
	return this->message;
}


QuantidadeColunasInvalidaException::QuantidadeColunasInvalidaException(int linha, string nome) {
	this->message = "Erro na linha " + to_string(linha) + " no arquivo " + nome + "!\n";
	this->message += "A quantidade de colunas deve ser maior que 0\n\n";
}

string QuantidadeColunasInvalidaException::getMessage() {
	return this->message;
}
