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
		std::cout << "number of played tickets - " << num_of_buyed_tickets << std::endl;
	}
}

void	ticket_database::print_statistic_by_winners()
{
	if (!winner)
	{
		std::cout << "YOU NEED TO GENERATE YOUR GAME" << std::endl;
		return ;
	}
	int	cnt = 0;
	std::iterator<std::bidirectional_iterator_tag, std::shared_ptr<ticket> > it = col->begin();

	std::cout << *it << std::endl;
	while (it != col->end())
	{
			
	}
}

void	ticket_database::generate(int n)
{
	col->clear();

	std::mt19937 gen(time(NULL));
	std::uniform_int_distribution<int>	winner_generator(1, n);
	std::uniform_int_distribution<int>	number_generator(n / 2, n);

	int		win_number = winner_generator(gen);
	this->num_of_buyed_tickets = number_generator(gen);
	winner = fabr->create_win_ticket(win_number);
	for (int i = 0; i < win_number; i++)
	{
		col->add(fabr->create_ticket(i + 1));
	}
	col->add(winner);
	for (int i = win_number + 1; i < n; i++)
	{
		col->add(fabr->create_ticket(i));
	}
}