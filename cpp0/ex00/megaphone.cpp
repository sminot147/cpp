#include <cctype>
#include <string>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	std::string str;
	int i = 0;
	while (argv[++i])
	{
		str += argv[i];
	}
	for (size_t j = 0; j < str.length(); j++)
	{
		str[j] = std::toupper(str[j]);
	}
	std::cout << str << std::endl;
	return (0);
}
