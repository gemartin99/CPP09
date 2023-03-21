#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include <deque>
#include <algorithm>
#include <ctime>

#include "PmergeMe.hpp"

static bool is_digits(std::string &str)
{
    return (str.find_first_not_of("0123456789") == std::string::npos);
}

void write_error(std::string s)
{
	std::cout << s << std::endl;
	exit (1);
}

void check_max(char *s)
{
	int i = -1;
	while (s[++i])
		;
	if (i > 11 || (i == 10 && (strncmp("2147483647", s, i) < 0)) || (i == 11 && (strncmp("-2147483648", s, i) < 0)))
		write_error("Error");
}

int main(int argc, char **argv)
{
	if (argc > 3001)
		write_error("Error");
	int i = 1;
	int j;
	while (argv[i])
	{
		std::string s = argv[i];
		if (!is_digits(s))
			write_error("Error");
		i++;
	}
	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (atoi(argv[j]) == atoi(argv[i]))
				write_error("Error: duplicate number.");
			j++;
		}
		check_max(argv[i]);
		i++;
	}
	i = 1;
	std::list<int> list;
	std::deque<int> deque;
	std::cout << "Before:  ";
	float time00;
	float time01;
	static clock_t start00;
	static clock_t start01;
	while (argv[i])
	{
		std::cout << argv[i] << " ";
		int n = atoi(argv[i]);
		start00 = clock();
		list.push_back(n);
		time00 = time00 + static_cast<float>(clock() - start00) / CLOCKS_PER_SEC;
		start01 = clock();
		deque.push_front(n);
		time01 = time01 + static_cast<float>(clock() - start01) / CLOCKS_PER_SEC;
		i++;
	}
	std::cout << std::endl;
	std::cout << "After:  ";
	static clock_t start1 = clock();
	list.sort();
	float time1 = time00 + static_cast<float>(clock() - start1) / CLOCKS_PER_SEC;
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it) {
		int num = *it;
    	std::cout << num << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::list : " << std::to_string(time1) << " us"<< std::endl; 
	static clock_t start2 = clock();
	std::sort(deque.begin(), deque.end());
	float time2 = time01 + static_cast<float>(clock() - start2) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << std::to_string(time2) << " us"<< std::endl; 
	return (0);
}