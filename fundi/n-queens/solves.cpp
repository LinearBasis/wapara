#include "strat.hpp"
#include <set>

void	Solve::print()
{
	for (int i = 0; i < solve.size(); i++)
	{
		std::cout << (char)(solve[i] + 'a') << ":" << i << " ";
	}
	std::cout << std::endl;
}

int		num_of_diag_1(int i, int j)
{
	return (i + j);
}

int		num_of_diag_2(int i, int j, int size)
{
	return (size + (i - j));
}

int		num_of_lets(int i, int j)
{
	return (i);
}

int		num_of_digs(int i, int j)
{
	return (j);
}

static void _solve_r(std::vector <bool> digs,
			std::vector <bool> lets,
			std::vector <bool> diags1,
			std::vector <bool> diags2,
			std::vector <Solve> &ans,
			std::vector <int> &tmp)
{
	if (tmp.size() == lets.size())
	{
		ans.push_back(Solve(tmp));
		return ;
	}
	for (int i = 0; i < lets.size(); i++)
	{
		if (diags1[num_of_diag_1(i, tmp.size())] &&
			lets[num_of_lets(i, tmp.size())] &&
			digs[num_of_digs(i, tmp.size())] &&
			diags2[num_of_diag_2(i, tmp.size(), lets.size())])
		{
			diags1[num_of_diag_1(i, tmp.size())] = false;
			lets[num_of_lets(i, tmp.size())] = false;
			digs[num_of_digs(i, tmp.size())] = false;
			diags2[num_of_diag_2(i, tmp.size(), lets.size())] = false;
			tmp.push_back(i);
			_solve_r(digs, lets, diags1, diags2, ans, tmp);
			tmp.pop_back();
			diags1[num_of_diag_1(i, tmp.size())] = true;
			lets[num_of_lets(i, tmp.size())] = true;
			digs[num_of_digs(i, tmp.size())] = true;
			diags2[num_of_diag_2(i, tmp.size(), lets.size())] = true;
		}
	}
}

std::vector <Solve>	Solver_recursive::solve(int n)
{
	std::vector <bool>	digs(n, 1);
	std::vector <bool>	lets(n, 1);
	std::vector <bool>	diags1(2*n + 1, 1);
	std::vector <bool>	diags2(2*n + 1, 1);
	std::vector <Solve>	ans;
	std::vector <int> tmp;

	_solve_r(digs, lets, diags1, diags2, ans, tmp);
	return (ans);
}

void				swap(std::vector <int> &vec, int x, int y)
{
	int a = vec[x];
	vec[x] = vec[y];
	vec[y] = a;
}
bool				next_step(std::vector <int> &vec)
{
	int	j = vec.size() - 2;
	while (j != -1 && vec[j] >= vec[j + 1])
		j--;
	if (j == -1)
		return (false);
	int k = vec.size() - 1;
	while (vec[j] >= vec[k])
		k--;
	swap(vec, j, k);
	int l = j + 1;
	int r = vec.size() - 1;
	while (l < r)
		swap(vec, l++, r--);
	return (true);		
}

Solve				Solve::rotate_90()
{
	int a;
	int b;
	std::vector <int> ans(solve.size()); // size = 8 (0, 6) -> (1, 0)

	for (int i = 0; i < solve.size(); i++)
	{
		a = solve.size() - i - 1;
		b = solve[i];
		ans[b] = a;
	}
	Solve ans_ = Solve(ans);
	return (Solve(ans));
}

Solve				Solve::rotate_180()
{
	return (this->rotate_90().rotate_90());
}


Solve				Solve::rotate_270()
{
	int a;
	int b;
	std::vector <int> ans(solve.size()); // size = 8 (0, 6) -> (1, 0)

	for (int i = 0; i < solve.size(); i++)
	{
		a = solve.size() - solve[i] - 1;
		b = i;
		ans[a] = b;
	}
	Solve ans_ = Solve(ans);
	return (Solve(ans));
}


Solve				Solve::flip_x()
{
	int a;
	int b;
	std::vector <int> ans(solve.size());

	for (int i = 0; i < solve.size(); i++)
	{
		a = i;
		b = solve.size() - 1 - solve[i];
		ans[a] = b;
	}
	Solve ans_ = Solve(ans);
	return (Solve(ans));
}

Solve				Solve::flip_y()
{
	int a;
	int b;
	std::vector <int> ans(solve.size());

	for (int i = 0; i < solve.size(); i++)
	{
		a = solve[i];
		b = solve.size() - 1 - i;
		ans[a] = b;
	}
	Solve ans_ = Solve(ans);
	return (ans_);
}


void	Solve::print_deck()
{
	for (int i = 0; i < solve.size(); i++)
	{
		for (int j = 0; j < solve.size(); j++)
		{
			if (solve[j] == i)
				std::cout << "K";
			else
				std::cout << "0";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

bool				is_solve(std::vector <int> ans)
{
	int n = ans.size();

	std::set <int>	diags1;
	std::set <int>	diags2;
	std::set <int>	hor;
	std::set <int>	ver;

	for (int i = 0; i < n; i++)
	{
		if (diags1.find(num_of_diag_1(i, ans[i])) != diags1.end())
			return (false);
		if (diags2.find(num_of_diag_2(i, ans[i], ans.size())) != diags2.end())
			return (false);
		if (hor.find(num_of_lets(i, ans[i])) != hor.end())
			return (false);
		if (ver.find(num_of_digs(i, ans[i])) != ver.end())
			return (false);
		diags1.insert(num_of_diag_1(i, ans[i]));
		diags2.insert(num_of_diag_2(i, ans[i], ans.size()));
		hor.insert(num_of_lets(i, ans[i]));
		ver.insert(num_of_digs(i, ans[i]));
	}
	return (true);
}

std::vector <Solve> Solver_iterative::solve(int n)
{
	std::vector <int> vec;
	std::vector <Solve> ans;
	for (int i = 0; i < n; i++)
	{
		vec.push_back(i);
	}
	int count = 0;
	while (next_step(vec))
	{
		if (is_solve(vec))
			ans.push_back(vec);
		count++;
	}
	return (ans);
}

std::vector <Solve>	create_all_solve(std::vector <Solve> vec)
{
	std::vector <Solve>				ans;
	std::set <std::vector <int> >	ans_set;
	std::vector <int>				tmp;

	for (int i = 0; i < vec.size(); i++)
	{
		tmp = vec[i].solve;
		ans_set.insert(Solve(tmp).rotate_90().solve);
		ans_set.insert(Solve(tmp).rotate_90().flip_x().solve);
		ans_set.insert(Solve(tmp).rotate_90().flip_y().solve);
		ans_set.insert(Solve(tmp).rotate_180().solve);
		ans_set.insert(Solve(tmp).rotate_180().flip_x().solve);
		ans_set.insert(Solve(tmp).rotate_180().flip_y().solve);

		ans_set.insert(Solve(tmp).rotate_270().solve);
		ans_set.insert(Solve(tmp).rotate_270().flip_x().solve);
		ans_set.insert(Solve(tmp).rotate_270().flip_y().solve);
	
		ans_set.insert(Solve(tmp).flip_x().solve);
		ans_set.insert(Solve(tmp).flip_y().solve);
	}
	for (auto &i : ans_set)
		ans.push_back(Solve(i));
	return (ans);
}

void	print_all_solve(std::vector <Solve> vec)
{
	for (auto &i : vec)
		i.print();
}

int	main()
{
	std::vector <Solve>	ans2;
	std::vector <Solve>	ans1;

	ans1 = Solver_recursive().solve(8);
	ans2 = Solver_iterative().solve(8);

	ans1 = create_all_solve(ans1);		//	ТУТ ПОВОРОТЫ И ОТРАЖЕНИЯ, НО ОНИ БЕСПОЛЕЗНЫ
	ans2 = create_all_solve(ans2);		//	РЕАЛИЗОВАЛ ЧИСТО ЧТОБЫ РЕАЛИЗОВАТЬ


	std::cout << "___" << std::endl;
	std::cout << "ANSES REC - " << ans1.size() << std::endl;
	std::cout << "ANSES ITER - " << ans2.size() << std::endl;
}

