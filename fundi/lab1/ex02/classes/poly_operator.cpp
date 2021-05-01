#include "polynom.h"

Polynomial&				Polynomial::operator+=(const Polynomial& poly)	// O( (n + m)log(n + m) )
{
	monoms.insert(monoms.end(), poly.monoms.begin(), poly.monoms.end());
	compress();
	return (*this);
}

Polynomial&				Polynomial::operator-=(const Polynomial& poly)	// O( (n + m)log(n + m) )
{
	std::list<Monomial> lst = poly.monoms;
	std::list<Monomial>::iterator iter;

	for (auto &i : lst)
		i.n *= -1;
	monoms.insert(monoms.end(), lst.begin(), lst.end());
	compress();
	return (*this);
}

Polynomial&				Polynomial::operator*=(const Polynomial& poly)	// O(nm) + O (nm * log (nm))
{
	std::list<Monomial>					lst;

	for (const auto &i : poly.monoms)
		for (const auto &j : monoms)
			lst.push_back(j * i);
	monoms = lst;
	compress();
	return (*this);
}

Polynomial&				Polynomial::operator*=(int k)
{
	std::list<Monomial>::iterator	iter;

	if (k == 0)
		monoms.clear();
	iter = monoms.begin();
	while (iter != monoms.end())
	{
		iter->n *= k;
		iter++;
	}
	return (*this);
}

Polynomial&				Polynomial::operator/=(char c)
{
	for (auto &i : monoms)
		i /= c;
	clear_zeroes();
	return (*this);
}

Polynomial				Polynomial::operator+(const Polynomial& poly) const
{
	Polynomial	ans(*this);

	ans += poly;
	return (ans);
}

Polynomial				Polynomial::operator-(const Polynomial& poly) const
{
	Polynomial	ans(*this);

	ans -= poly;
	return (ans);
}
Polynomial				Polynomial::operator*(const Polynomial& poly) const
{
	Polynomial	ans(*this);

	ans *= poly;
	return (ans);
}
Polynomial				Polynomial::operator*(int k) const
{
	Polynomial	ans(*this);

	ans *= k;
	return (ans);
}
Polynomial				Polynomial::operator/(char c) const
{
	Polynomial	ans(*this);

	ans /= c;
	return (ans);
}

std::string	Polynomial::get_poly_str() const
{
	std::string							ans;
	std::list<Monomial>::const_iterator	iter1;

	iter1 = monoms.begin();
	if (iter1 == monoms.end())
		ans += "0";
	while (iter1 != monoms.end())
	{
		ans += iter1->get_str();
		iter1++;
		if (iter1 != monoms.end())
		{
			ans += " + ";
		}
	}
}

std::ostream&			operator<<(std::ostream& fout, const Polynomial& poly)
{
	
	fout << poly.get_poly_str();
	return (fout);
}
