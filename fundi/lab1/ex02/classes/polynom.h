#pragma	once
#include "monom.h"

class	Polynomial
{
private:
	void	clear_zeroes(); // std::list<Monomial>	monoms;

public:
	std::list<Monomial>	monoms;
	Polynomial();
	Polynomial(const Polynomial& poly);
	Polynomial(const std::string &poly_str);
	Polynomial(std::list <Monomial> mons);		// ПЕРЕНЕСТИ В ПРИВАТ, КОГДА НАПИШУ ПАРСЕР
	void	compress();							// ТО ЖЕ САМОЕ

	Polynomial&				operator+=(const Polynomial& poly);
	Polynomial&				operator-=(const Polynomial& poly);
	Polynomial&				operator*=(const Polynomial& poly);
	Polynomial&				operator*=(int k);
	Polynomial&				operator/=(char c);

	Polynomial				operator+(const Polynomial& poly) const;
	Polynomial				operator-(const Polynomial& poly) const;
	Polynomial				operator*(const Polynomial& poly) const;
	Polynomial				operator*(int k) const;
	Polynomial				operator/(char c) const;

	friend std::ostream&	operator<<(std::ostream& fout, const Polynomial& poly);
	friend std::istream&	operator>>(std::istream& fin, Polynomial& poly);

};