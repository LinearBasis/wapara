#include "classes/polynom.h"

// int		main()
// {
// 	using namespace std;
// 	std::ifstream	fin("in.txt");
// 	Monomial		mon;

// 	int j = 0;
// 	while (!fin.eof())
// 	{
// 		j++;
// 		cout << "TEST #" << j << endl;
// 		try
// 		{
// 			fin >> mon;
// 			cout << mon;
// 			cout << equal_pows(mon, Monomial("x"));
// 		}
// 		catch (const exception &e)
// 		{
// 			cerr << "ERROR:\n";
// 			cerr << e.what() << '\n';
// 		}
// 		cout << "_________________" << endl;
// 	}
// }

int		main()
{
	Polynomial	pol1;
	Polynomial	pol2;
	char		c;
	std::string	str;

	std::ifstream fin("in.txt");
	fin >> pol1 >> c;
	std::getline(fin, str);
	fin >> pol2;
	std::cout << pol1 << std::endl << c << std::endl << pol2 << std::endl;
}