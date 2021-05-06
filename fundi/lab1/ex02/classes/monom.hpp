#pragma once
#include <list>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "TeX_convertible.hpp"


class Monomial : public Tex_convertible
{
private:
	friend class			Polynomial;
	std::map <char, int>	pows;
	int						n;

	int						add_one_variable(std::string str, int &i);
	std::string				create_monom(std::string str);
	std::string				get_str() const;
	friend bool				equal_pows(const Monomial& monom1, const Monomial& monom2);

public:
	Monomial();
	Monomial(const Monomial& monom);
	Monomial(const std::string &monom_str);
	Monomial(std::map <char, int> pows, int n);
	virtual ~Monomial();

	Monomial&				operator+=(const Monomial& monom);
	Monomial&				operator-=(const Monomial& monom);
	Monomial&				operator*=(const Monomial& monom);
	Monomial&				operator*=(int k);
	Monomial&				operator/=(char c);

	Monomial				operator+(const Monomial& monom) const;
	Monomial				operator-(const Monomial& monom) const;
	Monomial				operator*(const Monomial& monom) const;
	Monomial				operator*(int k) const; //да, я знаю, что надо бы реализовать еще и k * MONOM)))))
	Monomial				operator/(char c) const;

	friend std::ostream&	operator<<(std::ostream& fout, const Monomial& monom);
	friend std::istream&	operator>>(std::istream& fin, Monomial& monom);
	friend Monomial			create_monom_from_tokens(std::vector <std::string> monoms);

	std::string				convert() const override;
};

std::string					get_token_from_i(std::string str, int &i, char delimeter);
// std::vector <std::string>	tokenize_this_string(const std::string &str);
// bool						check_tokenized_string(std::vector <std::string> tok);
// std::vector <std::string>	tokenize_this_string(const std::string &str, char *delimeter);
