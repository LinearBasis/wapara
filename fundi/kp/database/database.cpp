#include "database.hpp"

database::~database()
{
}

void	database::print()
{
	col->print();
	std::cout << "WINNER - " << std::endl;
	std::cout << winner << std::endl;
	
}

void	database::generate(int n)
{
	col->clear();

	for (int i = 0; i < n; i++)
	{
		col->add(fabr->create_ticket());
	}
	winner = fabr->create_win_ticket();
}