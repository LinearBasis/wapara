/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 21:03:51 by dnicki            #+#    #+#             */
/*   Updated: 2021/02/18 22:13:42 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
//#include "TeX_convertible.h"
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <exception>
#include <string>
#include <iostream>
#include <utility>

class Matrix_square
{
private:
	double			**arr;
	int	size;

	void								free_mem();
	void								alloc_mem();
	void								E(int size_);
	

public:
	Matrix_square(); //+
	Matrix_square(const Matrix_square &matr); //+
	Matrix_square(const double **arr_, int size_); //+
	Matrix_square(int size_);
	Matrix_square(std::vector <std::vector <double> > vec); //+
	~Matrix_square();

	Matrix_square&			operator=(const Matrix_square &matr);
	double*					operator[](int i) const; //+
	Matrix_square			operator+(const Matrix_square &matr) const; //+
	Matrix_square			operator-(const Matrix_square &matr) const; //+
	Matrix_square			operator-() const; //+
	Matrix_square			operator*(const Matrix_square &matr) const; 
	Matrix_square			operator*(double num) const;
	friend Matrix_square	operator*(double num, const Matrix_square &matr); //+
	Matrix_square			operator/(double num) const; //+
	
	void					operator+=(const Matrix_square &matr); //+
	void					operator-=(const Matrix_square &matr); //+
	void					operator*=(const Matrix_square &matr); //+
	void					operator*=(double num); //+
	void					operator/=(double num); //+

	friend std::ostream&	operator<<(std::ostream& fout, const Matrix_square &matr); //+
	friend std::istream&	operator>>(std::istream& fin, Matrix_square &matr); //+

	bool					operator==(const Matrix_square &matr) const; //+
	bool					operator!=(const Matrix_square &matr)const; //+

	friend double			det(const Matrix_square &matr); //+
	friend Matrix_square	inv(const Matrix_square &matr); //+
	friend Matrix_square	trans(const Matrix_square &matr); //+
	friend double			trace(const Matrix_square &matr); //+
	friend double			exp(const Matrix_square &matr); //+

	
	friend Matrix_square	parse_string(std::string readed);
	

	//std::string convert() const override;
};

Matrix_square	parse_expression(std::istream &fin, std::ostream &fout);
Matrix_square	parse_string(std::string readed);