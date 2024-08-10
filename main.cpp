#include "chess.hpp"

int main()
{
	Chess my_chess("board.txt");
	my_chess.show();

	if (my_chess.analyse())
		std::cout << "_______Checkmate in 1 step________" << std::endl;
	else
	{
		my_chess.show();
		std::cout << "__________NOT checkmate___________" << std::endl;

		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "Trying next step for putting in check . . ." << std::endl;

		std::cout << std::endl;
		std::cout << std::endl;

		if (my_chess.putBkInCheck())
		{
			std::cout << "__________BK is in check__________" << std::endl;

			my_chess.show();
			std::cout << std::endl;

			if (my_chess.analyse())
				std::cout << "_______Checkmate in 2 steps_______" << std::endl;
			else
			{
				std::cout << "_____NOT Checkmate in 2 steps_____" << std::endl;
				std::cout << std::endl;
				my_chess.show();
			}
		}
		else
			std::cout << "Not possible to put in check with 1 step" << std::endl;
	}
	return 0;
}
