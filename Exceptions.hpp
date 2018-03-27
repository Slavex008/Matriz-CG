#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <string>

class QuantidadeLinhasInvalidaException {
	private:
		std::string message;
	public:
		QuantidadeLinhasInvalidaException(int linha, std::string nome);
		std::string getMessage();
	
};

class QuantidadeColunasInvalidaException {
	private:
		std::string message;
	public:
		QuantidadeColunasInvalidaException(int linha, std::string nome);
		std::string getMessage();
	
};



#endif
