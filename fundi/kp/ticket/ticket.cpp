#include "ticket.hpp"

ticket_6_49::ticket_6_49() : ticket()
{
}

ticket_6_49::~ticket_6_49()
{
}

std::ostream&	operator<<(std::ostream &fout, const ticket &tick)
{
	fout << (int)tick.size << " : ";
	for (int i = 0; i < tick.size; i++)
	{
		fout << (int)tick.numbers[i] << " ";
	}
	fout << std::endl;
	return (fout);
}

std::ostream&	operator<<(std::ostream &fout, const std::shared_ptr<ticket> &tick)
{
	fout << (int)tick->size << " : ";
	for (int i = 0; i < tick->size; i++)
	{
		fout << (int)tick->numbers[i] << " ";
	}
	fout << std::endl;
	return (fout);
}

bool	ticket::operator==(const ticket &tick)
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


bool	ticket::operator!=(const ticket &tick)
{
	return (!(*this == tick));
}