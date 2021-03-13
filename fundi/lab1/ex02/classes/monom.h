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
	Monomial&				operator+=(Monomial& monom) const;
	Monomial&				operator-=(Monomial& monom) const;
	Monomial&				operator*=(Monomial& monom)const;
	Monomial&				operator*=(int k) const;
	Monomial&				operator/=(Monomial& monom) const;
	void					add(std::string str);
	std::string				get_str();
public:
	Monomial();
	Monomial(const std::string &monom_str);
	Monomial(const Monomial& monom);
	Monomial&				operator+(const Monomial& monom) const;
	Monomial&				operator-(const Monomial& monom) const;
	Monomial&				operator*(const Monomial& monom) const;
	Monomial&				operator*(int k) const;
	Monomial&				operator/(const Monomial& monom) const;
	friend Monomial			create_monom_from_tokens(std::vector <std::string> monoms);
};

std::vector <std::string>	tokenize_this_string(std::string str);
bool						check_tokenized_string(std::vector <std::string> tok);
