#include "poly.hpp"


bool	element_of_field::get_byte(int n) const
{
	return (((field >> (n)) & 1) > 0);
}


element_of_field::element_of_field(const element_of_field &elem)
{
	this->field = elem.field;
}

element_of_field::element_of_field(unsigned short n)
{
	field = n;
}

element_of_field::~element_of_field()
{
	
}

element_of_field simple_mult(const element_of_field &first, const element_of_field &second)
{
	element_of_field	ans(0);

	for (int i = 7; i >= 0; i--)
	{
		if (second.get_byte(i))
		{
			// std::cout << element_of_field(first.field << i) << std::endl;
			ans = sum(ans, element_of_field(first.field << i));
			// std::cout << i << std::endl;
		}
	}

	return (ans);
}

element_of_field mod(const element_of_field &first, const element_of_field &second)
{
	element_of_field	ans(first.field);
	element_of_field	der(0);
	int					max_pow_of_first = 0;

	int j;
	j = 16;
	while (j >= 0)
	{
		{
			if (second.get_byte(j))
				break ;
			j--;
		}
	}

	while (second.field)
	{
		for (int i = 0; i < 16; i++)
			if (ans.get_byte(i))
				max_pow_of_first = i;
		int k = 0;

		if (j > 0)
			ans = sum(ans, second.field << (max_pow_of_first - j));
		if (j >= max_pow_of_first)
			break ;
	}
	return (ans);
}

std::ostream& operator<<(std::ostream &out, const element_of_field &elem)
{
	int j = 0;

	if (elem.field == 0)
		out << "0";

	for (int i = 14; i >= 0; i--)
	{
		if (elem.get_byte(i))
		{
			if (j != 0)
			{
				out << " + ";
			}
			if (i == 1)
			{
				std::cout << "x";
			}
			if (i == 0)
			{
				std::cout << "1";
			}
			if (i > 1)
			{
				std::cout << "x^" << i;
			}
			j++;			
		}
	}
	return (out);
}

element_of_field	mult(element_of_field first, element_of_field second)
{
	return (mod(simple_mult(first, second), element_of_field(283)));
}

element_of_field	pow(element_of_field elem, unsigned int _pow)
{
	if (_pow == 0)
		return (element_of_field(1));
	else if (_pow % 2)
		return (mult(elem, pow(elem, _pow - 1)));
	return (pow(mult(elem, elem), _pow / 2));
}

element_of_field	sum(const element_of_field &first, const element_of_field &second)
{
	element_of_field ans((first.field ^ second.field));
	return (ans);
}

element_of_field	reverse(element_of_field elem)
{
	return (pow(elem, 254));
}

std::vector<element_of_field>	get_all_irreducible_poly()
{
	std::vector <element_of_field>	ans;

	int j;
	for (int i = 257; i < 512; i += 2)
	{
		element_of_field	a(i);
		for (j = 2; j < 32; j++)
		{
			element_of_field	b(j);
			// std::cout << a << " mod " << b << " = " << mod(a, b) << std::endl;
			if (mod(a, b).field == 0)
			{
				j = 2;
				break;
			}
		}
		if (j == 32)
			ans.push_back(a);
	}
	return (ans);
}






int	main()
{
	element_of_field	f1(125);
	element_of_field	f2(133);

	std::cout << f1 << " + " << f2 << " =" << std::endl;
	std::cout <<  sum(f1, f2) << std::endl;
	std::cout << pow(f1, 2) << " = " << pow(f1, 2).number() << std::endl;
	std::cout << mult(f1, reverse(f1)) << std::endl;

	std::cout << "irred num - " << get_all_irreducible_poly().size() << std::endl;
	// std::cout << sizeof(char&) << std::endl;
	// std::cout << sizeof(char*) << std::endl;
	// std::cout << sizeof(char) << std::endl;
}
