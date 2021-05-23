#include "../all_headers.hpp"

ticket_database::~ticket_database()
{
}

void	ticket_database::print()
{
	if (winner)
	{
		col->print();
		std::cout << "WINNER - " << std::endl;
		std::cout << winner << std::endl;
	}
}

void	ticket_database::generate(int n)
{
	col->clear();

	std::mt19937 gen(time(NULL));
	std::uniform_int_distribution<int>	winner_generator(1, n);

	int		win_number = winner_generator(gen);

	winner = fabr->create_win_ticket(win_number);
	col->add(winner);
	for (int i = 0; i < win_number; i++)
	{
		col->add(fabr->create_ticket(i));
	}
	for (int i = win_number + 1; i < n; i++)
	{
		col->add(fabr->create_ticket(i));
	}
}