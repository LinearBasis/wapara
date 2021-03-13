#include "monom.h"

Monomial::Monomial()
{
	this->n = 1;
}

Monomial::Monomial(const Monomial &monom)
{
	this->n = monom.n;
	this->pows = monom.pows;
}