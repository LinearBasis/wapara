#include "monom.h"

Monomial create_monom_from_tokens(std::vector <std::string> monoms);

Monomial::Monomial()
{
	this->n = 1;
}

Monomial::Monomial(const Monomial &monom)
{
	this->n = monom.n;
	this->pows = monom.pows;
}

Monomial::Monomial(const std::string &monom_str)
{
	try
	{
		*this = create_monom_from_tokens(tokenize_this_string(monom_str));
	}
	catch (std::exception &ex)
	{
		*this = Monomial();
	}
}