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
	Monomial	mon1;

	std::ifstream fin("in.txt");
	fin >> pol1;
}