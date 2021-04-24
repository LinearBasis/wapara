#pragma once
#include <list>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>

class Monomial
{
private:
	std::map <char, int>	pows;
	int						n;

	void					add(std::string str);
	std::string				get_str() const;
	friend bool				equal_pows(const Monomial& monom1, const Monomial& monom2);

public:
	Monomial();
	Monomial(const Monomial& monom);
	Monomial(const std::string &monom_str);

	Monomial&				operator+=(const Monomial& monom);
	Monomial&				operator-=(const Monomial& monom);
	Monomial&				operator*=(const Monomial& monom);
	Monomial&				operator*=(int k);
	Monomial&				operator/=(char c);

	Monomial				operator+(const Monomial& monom) const;
	Monomial				operator-(const Monomial& monom) const;
	Monomial				operator*(const Monomial& monom) const;
	Monomial				operator*(int k);
	Monomial				operator/(char c) const;

	friend std::ostream&	operator<<(std::ostream& fout, const Monomial& monom);
	friend std::istream&	operator>>(std::istream& fin, Monomial& monom);



	friend Monomial			create_monom_from_tokens(std::vector <std::string> monoms);
	friend class			Polynomial;
};

std::vector <std::string>	tokenize_this_string(const std::string &str);
bool						check_tokenized_string(std::vector <std::string> tok);
