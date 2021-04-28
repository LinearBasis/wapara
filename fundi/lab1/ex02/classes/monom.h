#pragma once
#include <list>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
// #include "polynom.h"


class Monomial
{
private:
	friend class			Polynomial;
	std::map <char, int>	pows;
	int						n;

	void					add(std::string str);
	std::string				get_str() const;
	friend bool				equal_pows(const Monomial& monom1, const Monomial& monom2);

public:
	Monomial();
	Monomial(const Monomial& monom);
	Monomial(const std::string &monom_str);
	Monomial(std::map <char, int> pows, int n);

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

	bool					operator>(const Monomial& monom) const; 

	friend std::ostream&	operator<<(std::ostream& fout, const Monomial& monom);
	friend std::istream&	operator>>(std::istream& fin, Monomial& monom);

	friend Monomial			create_monom_from_tokens(std::vector <std::string> monoms);
	friend bool				compare_monoms(Monomial &mon1, Monomial &mon2);
};

std::string					get_token_from_i(std::string str, int &i, char delimeter);
std::vector <std::string>	tokenize_this_string(const std::string &str);
// bool						check_tokenized_string(std::vector <std::string> tok);
std::vector <std::string>	tokenize_this_string(const std::string &str, char *delimeter);
