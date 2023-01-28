#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <array>
#include <iostream>

struct square {
	square()
	{
		col = 0;
		row = 0;
	}
	square(size_t row1, size_t col1)
	{
		col = col1;
		row = row1;
	}
	size_t col;
	size_t row;
};

const size_t SIZE = 9;

typedef std::array<std::array<size_t, SIZE>, SIZE> Board;

void print(Board& board);

square findNextBox(Board& board);

bool isValid(size_t& value, square co, Board& board);

Board solve(Board board);

#endif