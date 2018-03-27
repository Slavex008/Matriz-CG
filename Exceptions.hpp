#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <string>

class Exception {
	private:
		std::string message;
	public:
		Exception(int linha, std::string nome, std::string descricao);
		std::string getMessage();
};


class QuantidadeLinhasInvalidaException : public Exception {
	public:
		QuantidadeLinhasInvalidaException(int linha, std::string nome);
		std::string getMessage();
};

class QuantidadeColunasInvalidaException : public Exception {
	public:
		QuantidadeColunasInvalidaException(int linha, std::string nome);
		std::string getMessage();
	
};



#endif
