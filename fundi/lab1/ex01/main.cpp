//#include "classes/TeX_convertible.h"
#include "classes/Matrix_square.h"

#include <iostream>
#include <fstream>
int		main()
{
	Matrix_square a;

	std::ifstream	f("file.txt");
	f >> a;
	std::ofstream	o("out.txt");
	o << a;
}
