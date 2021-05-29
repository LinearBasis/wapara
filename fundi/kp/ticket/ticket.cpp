#include "ticket.hpp"
#define FIXED_WIN 50
#include <set>

std::ostream&	operator<<(std::ostream &fout, const ticket &tick)
{
	fout << "№" << tick.id << " " << (int)tick.size << " : ";
	for (int i = 0; i < tick.size; i++)
	{
		fout << (int)tick.numbers[i] << " ";
	}
	fout << std::endl;
	return (fout);
}

std::ostream&	operator<<(std::ostream &fout, const std::shared_ptr<ticket> &tick)
{
	fout << "№" << tick->id << " " << (int)tick->size << " : ";
	for (int i = 0; i < tick->size; i++)
	{
		fout << (int)tick->numbers[i] << " ";
	}
	fout << std::endl;
	return (fout);
}

int			check_win(const ticket &tick, const ticket &winner)
{
	std::set <unsigned char>	set;

	int		counter = 0;
	int		i;
	
	for (i = 0; i < winner.get_size(); i++)
		set.insert(winner.get_numbers(i));
	for (i = 0; i < tick.get_size(); i++)
		if (set.count(tick.get_numbers(i)))
			counter++;
	return (counter);
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
