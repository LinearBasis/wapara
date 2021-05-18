#pragma	once
#include "monom.hpp"

class	Polynomial : public Tex_convertible
{
private:
	std::string	get_poly_str() const;
	void		clear_zeroes(); // std::list<Monomial>	monoms;
	std::string	add_monom_and_return_poly_str(std::string str, int sign);
	char		get_first_char_from_first_list_element();
	int			get_size_of_first_list_element();

public:
	std::list<Monomial>	monoms; // PRIVATE!
	Polynomial();
	Polynomial(const Polynomial& poly);
	Polynomial(const std::string &poly_str);
	~Polynomial();
	Polynomial(std::list <Monomial> mons);
	void	compress();							// ТО ЖЕ САМОЕ
	Polynomial				create_from_str(std::string str); //ТО ЖЕ САМОЕ

	Polynomial&				operator+=(const Polynomial& poly);
	Polynomial&				operator-=(const Polynomial& poly);
	Polynomial&				operator*=(const Polynomial& poly);
	Polynomial&				operator*=(int k);
	Polynomial&				operator/=(char c);
	Polynomial&				operator/=(char *c);

	Polynomial				operator+(const Polynomial& poly) const;
	Polynomial				operator-(const Polynomial& poly) const;
	Polynomial				operator*(const Polynomial& poly) const;
	Polynomial				operator*(int k) const;
	Polynomial				operator/(char c) const;


	friend std::ostream&	operator<<(std::ostream& fout, const Polynomial& poly);
	friend std::istream&	operator>>(std::istream& fin, Polynomial& poly);
	friend Polynomial		do_operation(Polynomial &pol1, char oper, Polynomial &pol2);
	friend Polynomial		parse_poly_expression(std::istream &fin);
	friend std::string		parse_poly_expression_to_str(std::istream &fin);

	std::string				convert() const override;
	friend std::vector <std::vector <std::string> >
								parse_all_file_to_tex(std::istream &fin);
	friend bool				is_homogeneous(const Polynomial &pol);
	friend bool				is_harmonic(const Polynomial &pol);

};

std::vector <std::vector <std::string> > parse_all_file_to_tex(std::istream &fin);
std::string		parse_poly_expression_to_str(std::istream &fin);
Polynomial		parse_poly_expression(std::istream &fin);
