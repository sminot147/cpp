#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av){
	if (ac != 4){
		std::cout << "Usage: <filename> <string to find> <string replace>" << std::endl;
		return 1;
	}

	//Open infile
	std::ifstream infile(av[1]);
	if (!infile){
		std::cout << "Error: Cannot open the file : " << av[1] << std::endl;
		return 1;
	}

	std::string	outFileName = av[1];
	outFileName.append(".replace");
	
	//Creat outfile
	std::ofstream   outfile(outFileName.c_str());
	if (!outfile) {
		std::cout << "Error: Cannot creat the file : " << av[1] << ".replace" << std::endl;
		infile.close();
		return 1;
	}

	//Replace without the fonction replace
	std::string toFind = av[2];
	std::string toReplace = av[3];
	size_t	lenToFind = toFind.length();
	std::string line;
	std::string::size_type pos;
	while (1){
		pos = 0;
		std::getline(infile, line);
		while ((pos = line.find(toFind, pos)) != std::string::npos){
			line = line.substr(0, pos) + toReplace + line.substr(pos + lenToFind);
			pos += lenToFind;
		}
		outfile << line;
		if (infile.eof())
			break ;
		outfile << std::endl;
	}
	infile.close();
	outfile.close();
	return 0;	
}
