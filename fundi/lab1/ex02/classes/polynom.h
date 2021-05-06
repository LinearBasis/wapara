#pragma	once
#include "monom.h"

class	Polynomial : public Tex_convertible
{
private:
	std::string	get_poly_str() const;
	void		clear_zeroes(); // std::list<Monomial>	monoms;
	std::string	add_monom_and_return_poly_str(std::string str, int sign);
	char		get_first_char_from_first_list_element();
	int			get_size_of_first_list_element();

	std::string	get_poly_str();

public:
	std::list<Monomial>	monoms;
	Polynomial();
	Polynomial(const Polynomial& poly);
	Polynomial(const std::string &poly_str);
	Polynomial(std::list <Monomial> mons);		// ПЕРЕНЕСТИ В ПРИВАТ, КОГДА НАПИШУ ПАРСЕР
	void	compress();							// ТО ЖЕ САМОЕ
	Polynomial				create_from_str(std::string str); //ТО ЖЕ САМОЕ

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
	friend Polynomial		do_operation(Polynomial &pol1, char oper, Polynomial &pol2);
	friend std::string		parse_expression(std::istream &fin);
	std::string				convert() const override;

};