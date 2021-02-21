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

class Matrix_square
{
private:
	double			**arr;
	unsigned int	size;

	void								free_mem();
	void								alloc_mem();

public:
	Matrix_square(); //+
	Matrix_square(Matrix_square &matr); //+
	Matrix_square(const double **arr_, unsigned int size_); //+
	Matrix_square(unsigned int size_);
	Matrix_square(std::vector <std::vector <double> > vec);
	~Matrix_square();


	Matrix_square&			operator=(Matrix_square &matr);
	double*					operator[](int i); //+
	Matrix_square			operator+(Matrix_square &matr); //+
	Matrix_square			operator-(Matrix_square &matr); //+
	Matrix_square			operator-(); //+
	Matrix_square			operator*(Matrix_square &matr); //+
	Matrix_square			operator*(double num); //+
	friend Matrix_square	operator*(double num, Matrix_square &matr); //+
	Matrix_square			operator/(double num); //+

	friend std::ostream&	operator<<(std::ostream& fout, Matrix_square &matr); //+
	friend std::istream&	operator>>(std::istream& fin, Matrix_square &matr);

	bool					operator==(const Matrix_square &matr);
	bool					operator!=(const Matrix_square &matr);

	friend double			det(const Matrix_square &matr);
	friend Matrix_square	inv_matrix(const Matrix_square &matr);
	friend Matrix_square	trans_matrix(const Matrix_square &matr);
	friend double			trace(const Matrix_square &matr);
	friend double			exp(const Matrix_square &matr);

	//std::string convert() const override;
};