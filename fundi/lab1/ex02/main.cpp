#include "classes/monom.h"

int		main()
{
	using namespace std;

	std::vector <std::string> ans;
	std::vector <std::string> test_strs;

	test_strs.push_back("x");
	test_strs.push_back("x * 2z^5");
	test_strs.push_back("a * -5b^-3 * d");
	test_strs.push_back("a * -3b^6 * c * -5d^3");
	test_strs.push_back("6x");
	for (int j = 0; j < (int)test_strs.size(); j++)
	{
		try
		{
			
				cout << "TEST #" << 1 + j << endl;
				ans = tokenize_this_string(test_strs[j]);
				if (ans.size() == 0)
					cout << "Norm, no poly" << endl;
				for (int i = 0; i < (int)ans.size(); i++)
					cout << ans[i] << endl;
				Monomial monom(test_strs[j]);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}