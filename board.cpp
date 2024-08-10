#include "board.hpp"

#include <fstream>
#include <iostream>

Board::Board(const std::string& path)
{
	std::ifstream	file(path);
	if (!file)
	{
		std::cerr << "Not able to open the file" << std::endl;
		exit (1);
	}

	std::string	line;
	while(std::getline(file, line))
		_board.push_back(line);

	file.close();
}

void	Board::show() const
{
	for (auto line : _board)
	{
		for (auto c : line)
		{
			if (c == '1')
				std::cout << "|||";
			if (c == '0')
				std::cout << "   ";
		}
		std::cout << std::endl;
	}
}
