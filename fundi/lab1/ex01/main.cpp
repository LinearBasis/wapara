//#include "classes/TeX_convertible.h"
#include "classes/Matrix_square.h"
#include <iostream>
#include <fstream>

int		main()
{
	Matrix_square a;


		std::ifstream	f("in.txt");
		f >> a;
		std::ofstream	o("out.txt");
		std::cout << det(a) << " - det " <<std::endl;
		o << a;
}
