#pragma once
#include <vector>
#include <iostream>

class element_of_field
{
private:
	unsigned short	field;
	bool			get_byte(int n) const;

	element_of_field();

public:
	int				number() {return (field);}
	friend element_of_field mod(const element_of_field &first, const element_of_field &second);
	friend element_of_field	sum(const element_of_field &first, const element_of_field &second);

	friend element_of_field	simple_mult(const element_of_field &first, const element_of_field &second);
	friend element_of_field	mult(element_of_field first, element_of_field second);

	friend element_of_field	pow(element_of_field elem, unsigned int _pow);
	friend element_of_field	reverse(element_of_field elem);
	friend std::vector<element_of_field>	get_all_irreducible_poly();

	friend std::ostream& operator<<(std::ostream &out, const element_of_field &elem);


	// element_of_field(std::vector<int> poly);
	element_of_field(const element_of_field &elem);
	element_of_field(unsigned short field);

	~element_of_field();
};
