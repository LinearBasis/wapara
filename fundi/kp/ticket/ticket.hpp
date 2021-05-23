#pragma once
#include <iostream>

class ticket
{
	friend class ticket_fabric_6_49;
	
	unsigned char	size;
	unsigned char	*numbers;


	bool					operator==(const ticket &tick);
	bool					operator!=(const ticket &tick);
	friend std::ostream&	operator<<(std::ostream &fout, const ticket &tick);
	friend std::ostream&	operator<<(std::ostream &fout, const 
										std::shared_ptr<ticket> &tick);
protected:
	virtual ~ticket() {delete numbers;};
	ticket() {};
public:
	unsigned char	get_size() {return (size);}
};


// 

class ticket_6_49 : public ticket
{
	friend class ticket_fabric_6_49;
public:


	ticket_6_49();
	~ticket_6_49();
};
