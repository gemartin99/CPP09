#include <iostream>
#include <fstream>
#include <string>
#include <vector>

static bool is_digits(std::string &str)
{
    return (str.find_first_not_of("0123456789.") == std::string::npos);
}

void write_error(std::string s)
{
	std::cerr << s << std::endl;
	exit (EXIT_FAILURE);
}

int check_date(std::string str)
{
	char *s = &str[0];
	int i = str.length();
	if (i < 14)
		return (-1);
	if (s[11] != '|')
		return (-1);
	if (s[4] != '-' || s[7] != '-')
		return (-1);
	std::string sub = str.substr(0, 4);
	char *res = &sub[0];
	if (atoi(res) < 2009 || atoi(res) > 2022)
		return (-1);
	sub = str.substr(5, 2);
	res = &sub[0];
	if (atoi(res) > 12 || atoi(res) == 0)
		return (-1);
	sub = str.substr(8, 2);
	res = &sub[0];
	if (atoi(res) > 31 || atoi(res) == 0)
		return (-1);
	return (0);
}

int check_more_than_one(char c, char *s)
{
	int i = 0;
	int j = 0;
	while (s[i])
	{
		if (s[i] == c)
			j++;
		i++;
	}
	if (j > 1)
		return (-1);
	return (0);
}

int check_digits(char *s)
{	
	std::string str;
	str.assign(s);
	if (s[0] == '.')
		return (-1);
	if (is_digits(str))
		return (0);
	return (-1);
}

int check_num(std::string str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == '|')
			break;
		i++;
	}
	i = i + 2;
	char *s = &str[i];
	if (s[i] == '-')
		return (-1);
	if (check_more_than_one('.', s) == -1)
		return (-3);
	if (check_digits(s) == -1)
		return (-4);
	float n = atof(s);
	if (n > 1000)
		return (-2);
	return (0);

}

int check_errors(std::string s)
{
	if (check_date(s) == -1)
		std::cerr << "Error: bad input => " << s << std::endl;
	else
	{
		int x = check_num(s);
		if (x == -1)
			std::cerr << "Error: not a positive number." << std::endl;
		else if (x == -2)
			std::cerr << "Error: too large a number." << std::endl;
		else if (x == -3)
			std::cerr << "Error: the number contains more than one dot." << std::endl;
		else if (x == -4)
			std::cerr << "Error: incorrect character." << std::endl;
		//else
		else if (x == 0)
			return (0);
	}
	return (-1);
}

int print_res(std::string s, std::vector<std::string> data, std::vector<std::string> value)
{
	std::string sub = s.substr(0, 10);
	for (unsigned int i = 0; i < data.size();i++)
	{
		//std::cout << sub << std::endl;
		if (sub == data[i])
		{
			std::string s1 = "|";
			std::string s2 = "=>";
			std::size_t found = s.find(s1);
			s.erase(found, s1.length());
			s.insert(found, s2);
			std::string res_s = s.substr(0, 14);
			std::cout << res_s; //<< std::endl;
			int x = 12;
			while (s[x] && s[x] != ' ')
				x++;
			x++;
			std::string sub2 = s.substr(x, s.length() - x);
			float res1 = stof(sub2);
			float res2 = stof(value[i]);
			float res = res1 * res2;
			std::cout << res << std::endl;
			break;
		}
	}
	return (0);
}

int main(int argc, char **argv)
{
	std::vector<std::string> date;
	std::vector<std::string> value;
	if (argc != 2)
		write_error("Error: could not open file.");
	std::ifstream csv("data.csv");
	std::string str;
	if (csv.is_open())
	{
		while (std::getline(csv, str))
		{
			int i = 0;
			while (str[i] && str[i] != ',')
				i++;
			std::string date_res = str.substr(0, i);
			i++;
			std::string value_res = str.substr(i, str.length() - i);
			date.push_back(date_res);
			value.push_back(value_res);
		}
	}
	std::ifstream file(argv[1]);
	std::string line;
	if (file.is_open())
	{
		while(getline(file, line))
		{
			if (check_errors(line) == 0)
				print_res(line, date, value);
		}
	}
	else
		write_error("Error: could not open file.");
	return (0);
}