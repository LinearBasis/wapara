#include "polynom.hpp"

Polynomial::Polynomial()
{
}

Polynomial::Polynomial(const Polynomial& poly)
{
	monoms = poly.monoms;
}

Polynomial::Polynomial(const std::string &poly_str)
{
	
}

Polynomial::Polynomial(std::list <Monomial> mons)
{
	monoms = mons;
}

Polynomial::~Polynomial()
{

}