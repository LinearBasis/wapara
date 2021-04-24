#include "monom.h"

std::ostream&	operator<<(std::ostream& fout, const Monomial& monom)
{
	fout << monom.get_str() << std::endl;

	return (fout);
}

Monomial&				Monomial::operator*=(const Monomial& monom)
{
	std::map <char, int>::const_iterator iter;

	iter = monom.pows.begin();
	n *= monom.n;
	if (n == 0)
	{
		pows.clear();
		return (*this);
	}
	while (iter != monom.pows.end())
	{
		if (pows.find((iter->first)) != pows.end())
		{
			if (pows[iter->first] != -1)
				pows[iter->first]+=iter->second;
			else
				pows.erase(iter->first);
		}
		else
		{
			pows.insert(*iter);
		}
		iter++;
	}
	return (*this);
}

Monomial				Monomial::operator*(const Monomial& monom) const
{
	Monomial ans(*this);

	ans *= monom;
	return (ans);
}

Monomial&				Monomial::operator/=(char c)
{
	if (pows.find(c) != pows.end())
	{
		pows[c]--;
		n *= pows[c] + 1;
		if (pows[c] == 0)
			pows.erase(c);
	}
	else
	{
		pows.clear();
		n = 0;
	}
	return (*this);
}

Monomial				Monomial::operator/(char c) const
{
	Monomial	copy(*this);
	
	copy /= c;
	return (copy);
}

Monomial&				Monomial::operator+=(const Monomial& monom)
{
	if (!equal_pows(*this, monom))
		throw std::logic_error("cant sum different monoms");
	n += monom.n;
	return (*this);
}

Monomial&				Monomial::operator-=(const Monomial& monom)
{
	if (!equal_pows(*this, monom))
		throw std::logic_error("cant sum different monoms");
	n -= monom.n;
	return (*this);
}

Monomial				Monomial::operator+(const Monomial& monom) const
{
	Monomial	ans(*this);

	ans += monom;
	return (ans);
}

Monomial				Monomial::operator-(const Monomial& monom) const
{
	Monomial	ans(*this);

	ans -= monom;
	return (ans);
}

