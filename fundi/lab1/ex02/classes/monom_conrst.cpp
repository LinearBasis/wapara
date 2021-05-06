#include "monom.hpp"

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
		this->create_monom(monom_str);
	}
	catch (std::exception &ex)
	{
		*this = Monomial();
	}
}

Monomial::Monomial(std::map <char, int> pows, int n)
{
	this->pows = pows;
	this->n = n;
}

Monomial::~Monomial()
{

}
