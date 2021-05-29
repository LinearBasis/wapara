#pragma once
#include <iostream>
#include <unordered_set>
#include <cmath>
#include <memory>

class ticket
{
	friend class ticket_fabric_6_49;
	friend class ticket_fabric_5_36;
	friend class ticket_fabric_4_20;

	template <template <class ...> class Collection> friend class ticket_database;

	int				id;
	unsigned char	size;
	unsigned char	*numbers;


	friend int				check_win(const ticket &tick, const ticket &winner);
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

	ticket_6_49() {};
	~ticket_6_49() {};
};

class ticket_4_20 : public ticket
{
	friend class ticket_fabric_4_20;
public:

	ticket_4_20() {};
	~ticket_4_20() {};
};



//4-20 : (4 - 7) (1 - 20)