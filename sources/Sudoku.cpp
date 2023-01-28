
#include "Sudoku.hpp"

square findNextBox(Board& board)
{
	square l(0,0);
	for (size_t row = 0; row < 9; row++)
	{
		for (size_t col = 0; col < 9; col++)
		{
			if (board[row][col] == 0)
			{
				l.row = row;
				l.col = col;
				return l;
			}
		}
	}
	l.row = 9;
	l.col = 9;
	return l;
}

bool isValid(size_t& value, square co, Board& board)
{		
	square temp1 = co;

	for (int x = 0; x < 9; x++)
	{
		if (board[x][co.col] == value)
		{
			return false;
		}
	}

	for (int x = 0; x < 9; x++)
	{
		if (board[co.row][x] == value)
		{
			return false;
		}
	}
	
	square holder(0,0);
	holder.row = temp1.row % 3;
	holder.col = temp1.col % 3;
	temp1.row = temp1.row - holder.row;
	temp1.col = temp1.col - holder.col;
	holder = temp1;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i + temp1.row][j + temp1.col] == value)
			{
				return false;
			}
		}
	}
	return true;
}

void print(Board &board)
{
	for (int i = 0; i < 9; i++) 
	{
		for (int j = 0; j < 9; j++) 
		{
			std::cout << board[i][j] << " ";
			if (j == 8)
			{
				std::cout << std::endl;
				if (i == 8)
				{
					std::cout << std::endl;
				}
			}
		}
	}
}

Board solve(Board board)
{
	square co1(0,0);
	square co = findNextBox(board);

	if (co.row == 9 && co.col == 9)
	{
		return board;
	}

	for (size_t value = 1; value <= 9; value++)
	{
		if (isValid(value, co, board))
		{
			Board modBoard = board;
			modBoard[co.row][co.col] = value;
			modBoard = solve(modBoard);
			co1 = findNextBox(modBoard);

			if (co1.row == 9)
			{
				return modBoard;
			}
		}
	}
	return board;
}
