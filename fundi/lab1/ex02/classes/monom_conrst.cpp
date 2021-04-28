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
		*this = create_monom_from_tokens(tokenize_this_string(monom_str, "*"));
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

std::istream&	operator>>(std::istream& fin, Monomial& monom)
{
	std::string	str;
	getline(fin, str);
	if (str[0] == 0)
		throw std::invalid_argument("empty string");
	std::cout << "STR - " << str << std::endl;
	monom = create_monom_from_tokens(tokenize_this_string(str, "*"));
	return (fin);
}