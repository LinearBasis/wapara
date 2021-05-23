#include "ticket.hpp"
#define FIXED_WIN 50

ticket_6_49::ticket_6_49() : ticket()
{
}

ticket_6_49::~ticket_6_49()
{
}

std::ostream&	operator<<(std::ostream &fout, const ticket &tick)
{
	fout << "№" << tick.number_of_ticket << " " << (int)tick.size << " : ";
	for (int i = 0; i < tick.size; i++)
	{
		fout << (int)tick.numbers[i] << " ";
	}
	fout << std::endl;
	return (fout);
}

std::ostream&	operator<<(std::ostream &fout, const std::shared_ptr<ticket> &tick)
{
	fout << "№" << tick->number_of_ticket << " " << (int)tick->size << " : ";
	for (int i = 0; i < tick->size; i++)
	{
		fout << (int)tick->numbers[i] << " ";
	}
	fout << std::endl;
	return (fout);
}

int						check_win(const ticket &tick, const ticket &winner)
{
	std::unordered_set <unsigned char>	set;

	int		counter = 0;
	int		begin_ans = winner.get_size();

	for (int i = 0; i < winner.get_size(); i++)
	{
		set.insert(winner.get_numbers(i));
	}
	for (int i = 0; i < tick.get_size(); i++)
	{
		if (set.count(tick.get_numbers(i)))
			counter++;
	}
	if (counter)
		return (FIXED_WIN * std::pow(begin_ans, counter - 1));
	return (0);
}


bool	ticket::operator==(const ticket &tick) const
{
	if (this->size != tick.size)
		return (false);
	for (int i = 0; i < tick.size; i++)
	{
		if (this->numbers[i] != tick.numbers[i])
			return (false);
	}
	return (true);
}


bool	ticket::operator!=(const ticket &tick) const
{
	return (!(*this == tick));
}

unsigned char	ticket::get_numbers(int i) const
{
	if (i < this->get_size())
	{
		return numbers[i];
	}
	throw std::invalid_argument("Try to get undefined element");
}
