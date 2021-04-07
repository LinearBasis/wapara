//#include "classes/TeX_convertible.h"
#include "classes/Matrix_square.h"
#include <iostream>
#include <fstream>

std::vector <std::vector <std::string> >	parse_all_expressions(std::istream &f)
{
	std::vector <std::string> parse_result;
	std::vector <std::vector <std::string> > ans;

	Matrix_square	a, b;
	std::string		asd;

	while (1)
	{
		try
		{
			parse_result = parse_expression(f);
			if (parse_result.size() == 0)
				break;
			ans.push_back(parse_result);
			std::cout << std::endl;
		}
		catch (std::exception &ex)
		{
			std::cerr << ex.what() << std::endl << "________" << std::endl;
		}
	}
	return (ans);
}


int		main()
{
	std::ifstream	f("in.txt");
	std::ofstream	o("out.txt");

	o << get_string_of_tex_expressions(parse_all_expressions(f));
}