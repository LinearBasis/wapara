#include "classes/monom.h"

int		main()
{
	using namespace std;
	std::ifstream	fin("in.txt");
	Monomial		mon;

	char c;
	int j = 0;
	while (1)
	{
		j++;
		cout << "TEST #" << j << endl;
		try
		{
			fin >> mon;
			fin >> c;
			cout << mon;
			if (cin.eof())
				return (0);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n'; //почему тут не endl?
		}
		if (j > 10)
			return (0);
		cout << "_________________" << endl;
	}
}