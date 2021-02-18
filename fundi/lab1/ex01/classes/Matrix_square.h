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

class Matrix_square
{
private:
	double			**arr;
	unsigned int	size;
public:
	Maxrix_square() const;
	Matrix_square(Matrix_square matr);
	Matrix_square(const double **arr, int size);
	Matrix_square(int size, std::ifstream);
	Matrix_square(std::ifstream);
	Matrix_square(const std::initializer_list<int> &list);
};
