#include "classes/polynom.hpp"

int		main()
{
	Polynomial	pol1;
	Polynomial	pol2;
	std::string	str;
	std::ifstream fin("in.txt");

	std::vector <std::vector <std::string> >	a;
	a = parse_all_file_to_tex(fin);
	for (auto i : a)
	{
		std::cout << "(" << i[0] << ")" << "\\:" << i[1] << "\\:(" << i[2]  << ")\\:=\\:" << i[3] << "\\newline" << std::endl;
	}
}

// int		main()
// {
// 	Polynomial	pol1;
// 	std::ifstream fin("in.txt");

// 	fin >> pol1;
// 	std::cout << is_harmonic(pol1);
// }
