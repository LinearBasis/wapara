#pragma once
#include "collection.hpp"
#include "../fabric/fabric.hpp"
#include <cstddef>

template <template <class ...> class Collection>
class ticket_database
{
private:
	ticket_database() {};
public:
	void					print();
	void					generate(int n);
	void					print_statistic_by_winners();
	std::shared_ptr<ticket>	find_winner();
	std::shared_ptr<ticket>	find_by_id(int id);
	std::shared_ptr<ticket>	find_by_numbers(int nums);


	int										num_of_bought_tickets;
	std::shared_ptr<ticket>					winner;
	Collection<std::shared_ptr<ticket> >	col;
	ticket_fabric							*fabr;

	ticket_database(ticket_fabric *_fabr) : fabr(_fabr) {};
	~ticket_database();
};

template <template <class ...> class Collection>
ticket_database<Collection>::~ticket_database()
{

}

template <template <class ...> class Collection>
std::shared_ptr<ticket>	ticket_database<Collection>::find_by_numbers(int nums)
{
	if (!winner)
	{
		throw std::logic_error("YOU NEED TO GENERATE YOUR GAME");
	}
	auto it = col.begin();

	int i = 0;
	while (it != col.end() && i++ < this->num_of_bought_tickets)
	{
		if (check_win(**it, *winner) == nums)
		{
			std::cout << "FIRST TICKET WITH : " << nums << " MATCH NUMBERS:" << std::endl << *it << std::endl;
			return (*it);
		}
		++it;
	}
	std::cout << "THERE ARE NO TICKET WITH " << nums << " MATCH NUMBERS IN GAME" << std::endl; 
	return (nullptr);
}

template <template <class ...> class Collection>
std::shared_ptr<ticket>	ticket_database<Collection>::find_winner()
{
	if (!winner)
	{
		throw std::logic_error("YOU NEED TO GENERATE YOUR GAME");
	}
	auto it = col.begin();

	int i = 0;
	while (it != col.end() && i++ < this->num_of_bought_tickets)
	{
		if (check_win(**it, *winner) == winner->size)
		{
			std::cout << "FIRST WINNER : " << std::endl << *it << std::endl;
			return (*it);
		}
		++it;
	}
	std::cout << "THERE ARE NO WINNER IN GAME" << std::endl; 
	return (nullptr);
}

template <template <class ...> class Collection>
std::shared_ptr<ticket>	ticket_database<Collection>::find_by_id(int id)
{
	if (!winner)
	{
		throw std::logic_error("YOU NEED TO GENERATE YOUR GAME");
	}
	auto it = col.begin();

	int i = 0;

	while (it != col.end() && i++ < this->num_of_bought_tickets)
	{
		if ((*it)->id == id)
		{
			std::cout << "TICKET WITH ID " << id << " :" << std::endl << *it << std::endl;
			return (*it);
		}
		++it;
	}
	std::cout << "THERE ARE NO TICKET WITH ID " << id << " IN GAME" << std::endl; 
	return (nullptr);
}


template <template <class ...> class Collection>
void	ticket_database<Collection>::print()
{
	if (winner)
	{
		col.print();
		std::cout << "WINNER - " << std::endl;
		std::cout << winner << std::endl;
		std::cout << "number of played tickets - " << num_of_bought_tickets << std::endl;
	}
}

template <template <class ...> class Collection>
void	ticket_database<Collection>::print_statistic_by_winners()
{
	if (!winner)
		throw std::logic_error("YOU NEED TO GENERATE YOUR GAME");
	auto it = col.begin();

	int		*arr = new int[winner->size + 1];

	std::cout << "NUMBER OF BOUGHT TICKETS - " << this->num_of_bought_tickets << std::endl;

	for (int i = 0; i < winner->size + 1; i++)
		arr[i] = 0;

	int i = 0;
	while (it != col.end() && i++ < this->num_of_bought_tickets)
	{
		if (*it != winner)
			arr[check_win(**it, *winner)]++;
		++it;
	}
	std::cout << "WINNERS STAT:" << std::endl;
	for (int i = 0; i < winner->size + 1; i++)
	{
		std::cout << i << " MATCH NUMBER - " << arr[i] << " TICKETS" << std::endl;
	}
	delete[] arr;
	std::cout << std::endl;
}

template <template <class ...> class Collection>
void	ticket_database<Collection>::generate(int n)
{
	col.clear();

	std::mt19937 gen(time(NULL));
	std::uniform_int_distribution<int>	winner_generator(1, n);
	std::uniform_int_distribution<int>	number_generator(n / 2, n);

	int		win_number = winner_generator(gen);
	this->num_of_bought_tickets = number_generator(gen);
	winner = fabr->create_win_ticket(win_number + 1);
	for (int i = 0; i < win_number; i++)
	{
		col.add(fabr->create_ticket(i + 1));
	}
	col.add(winner);
	for (int i = win_number + 1; i < n; i++)
	{
		col.add(fabr->create_ticket(i + 1));
	}
}