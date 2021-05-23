#pragma once
#include <iostream>
#include <unordered_set>

class ticket
{
	friend class ticket_fabric_6_49;

	int				number_of_ticket;
	unsigned char	size;
	unsigned char	*numbers;


	int						check_win(const ticket &tick, const ticket &winner);
	bool					operator==(const ticket &tick) const;
	bool					operator!=(const ticket &tick) const;
	friend std::ostream&	operator<<(std::ostream &fout, const ticket &tick);
	friend std::ostream&	operator<<(std::ostream &fout, const 
										std::shared_ptr<ticket> &tick);
protected:
	virtual ~ticket() {delete numbers;};
	ticket() {};
public:
	unsigned char	get_size() const {return (size);}
	unsigned char	get_numbers(int i) const;
};


// 

class ticket_6_49 : public ticket
{
	friend class ticket_fabric_6_49;
public:


	ticket_6_49();
	~ticket_6_49();
};
