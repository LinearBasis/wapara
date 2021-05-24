#include "all_headers.hpp"
#include <unistd.h>
#include <ctime>


template <template <class ...> class Collection>
int			play(ticket_database<Collection> base)
{
	int		n;

	while (1)
	{
		std::cout << "ENTER A NUMBER OF TICKETS" << std::endl;
		while (1)
		{
			std::cin >> n;

			if (!std::cin.fail())
				if (n > 1)
					break ;
			std::cin.clear();
			std::cin.ignore(32767,'\n');
			std::cout << "BAD INPUT, TRY AGAIN" << std::endl;
		}
		base.generate(n);
		std::cout << "YOU CAN FIND TICKETS IN GAME OR CHECK STATISTICS" << std::endl;
		while (1)
		{
			std::cout << "1: check statistics" << std ::endl;
			std::cout << "2: find first winner" << std ::endl;
			std::cout << "3: find by id" << std ::endl;
			std::cout << "4: find first ticket by number of match numbers" << std ::endl;
			std::cout << "5: next turn" << std ::endl;
			std::cout << "6: exit" << std ::endl << std::endl;

			int k;
			while (1)
			{
				std::cin >> k;

				if (!std::cin.fail())
					if ((k >= 0 && k <= 6))
						break ;
				std::cin.clear();
				std::cin.ignore(32767,'\n');
				std::cout << "BAD INPUT, TRY AGAIN" << std::endl;
			}
			if (k == 1)
			{
				base.print_statistic_by_winners();
			}
			else if (k == 2)
			{
				base.find_winner();
			}
			else if (k == 3)
			{
				std::cout << "enter id" << std::endl;
				int l;
				while (1)
				{
					std::cin >> l;

					if (!std::cin.fail())
						break ;
					std::cin.clear();
					std::cin.ignore(32767,'\n');
					std::cout << "BAD INPUT, TRY AGAIN" << std::endl;
				}
				base.find_by_id(l);
			}
			else if (k == 4)
			{
				int l;
				while (1)
				{
					std::cin >> l;

					if (!std::cin.fail())
						if (!(k >= 0 && k <= 5))
							break ;
					std::cin.clear();
					std::cin.ignore(32767,'\n');
					std::cout << "BAD INPUT, TRY AGAIN" << std::endl;
				}
				base.find_by_numbers(l);
			}
			else if (k == 5)
				break ;
			else if (k == 6)
				return (0);
		}
	}
}

void		game()
{
	std::cout << "CHOOSE GAMEMODE:" << std::endl;
	std::cout << "1: 4-20" << std::endl;
	std::cout << "2: 6-49" << std::endl;
	std::cout << "3: exit" << std::endl << std::endl;
	int i;

	while (1)
	{
		std::cin >> i;

		if (!std::cin.fail())
			if (i == 1 || i == 2 || i == 3)
				break ;
		std::cin.clear();
		std::cin.ignore(32767,'\n');
		std::cout << "BAD INPUT, TRY AGAIN" << std::endl;
	}
	if (i == 3)
	{
		std::cout << "GOODBYE" << std::endl;
		return ;
	}
	if (i == 1)
	{
		ticket_fabric_4_20	fabr;
		ticket_database<collection_list> base(&fabr);
		play(base);
	}
	else if (i == 2)
	{
		ticket_fabric_6_49	fabr;
		ticket_database<collection_forward_list> base(&fabr);
		play(base);
	}
}

int	main()
{
	game();

	// ticket_fabric_4_20	fabr;
	// ticket_database<collection_forward_list> base(&fabr);

	// clock_t start = clock();
	
	// base.generate(20 * 1000 * 10);
    
	// clock_t end = clock();
  	// double seconds = (double)(end - start) / 1000.0;
	
	// std::cout << "generated" << std::endl;
	// std::cout << "adding time(in seconds) - " << seconds / 1000.0 << std::endl;

	// start = clock();
	// base.print_statistic_by_winners();
	// end = clock();
  	// seconds = (double)(end - start) / 1000.;
	// std::cout << "winner stat time(in seconds) - " << seconds / 1000.0 << std::endl;
	// base.find_by_id(148800);
}