
#include <gtest/gtest.h>

#include "Sudoku.hpp"

TEST(TestfindNextBox, coordinate00) {
    Board board = {{{0, 1, 7, 8, 3, 2, 6, 4, 9}, //5
                    {9, 3, 6, 7, 4, 5, 8, 2, 1},
                    {8, 2, 4, 1, 9, 6, 3, 7, 5},
                    {1, 4, 5, 3, 7, 8, 2, 9, 6},
                    {6, 7, 3, 4, 2, 9, 5, 1, 8},
                    {2, 9, 8, 5, 6, 1, 4, 3, 7},
                    {7, 6, 2, 9, 8, 4, 1, 5, 3},
                    {3, 8, 1, 2, 5, 7, 9, 6, 4},
                    {4, 5, 9, 6, 1, 3, 7, 8, 2}}};
    square response = findNextBox(board);
    square answer(0,0);
    EXPECT_EQ(response.row, answer.row);
    EXPECT_EQ(response.col, answer.col);
}

TEST(TestfindNextBox, coordinateRightEdge84) {
    Board board = {{{5, 1, 7, 8, 3, 2, 6, 4, 9}, 
                    {9, 3, 6, 7, 4, 5, 8, 2, 1},
                    {8, 2, 4, 1, 9, 6, 3, 7, 5},
                    {1, 4, 5, 3, 7, 8, 2, 9, 6},
                    {6, 7, 3, 4, 2, 9, 5, 1, 0},
                    {2, 9, 8, 5, 6, 1, 4, 3, 7},
                    {7, 6, 2, 9, 8, 4, 1, 5, 3},
                    {3, 8, 1, 2, 5, 7, 9, 6, 4},
                    {4, 5, 9, 6, 1, 3, 7, 8, 2}}};
    square response = findNextBox(board);
    square answer(4,8);
    EXPECT_EQ(response.row, answer.row);
    EXPECT_EQ(response.col, answer.col);
}

TEST(TestfindNextBox, coordinateLeftEdge02) {
    Board board = {{{5, 1, 7, 8, 3, 2, 6, 4, 9}, 
                    {9, 3, 6, 7, 4, 5, 8, 2, 1},
                    {0, 2, 4, 1, 9, 6, 3, 7, 5},
                    {1, 4, 5, 3, 7, 8, 2, 9, 6},
                    {6, 7, 3, 4, 2, 9, 5, 1, 8},
                    {2, 9, 8, 5, 6, 1, 4, 3, 7},
                    {7, 6, 2, 9, 8, 4, 1, 5, 3},
                    {3, 8, 1, 2, 5, 7, 9, 6, 4},
                    {4, 5, 9, 6, 1, 3, 7, 8, 2}}};
    square response = findNextBox(board);
    square answer(2,0);
    EXPECT_EQ(response.row, answer.row);
    EXPECT_EQ(response.col, answer.col);
}

TEST(TestfindNextBox, coordinateCorner88) {
    Board board = {{{5, 1, 7, 8, 3, 2, 6, 4, 9}, 
                    {9, 3, 6, 7, 4, 5, 8, 2, 1},
                    {8, 2, 4, 1, 9, 6, 3, 7, 5},
                    {1, 4, 5, 3, 7, 8, 2, 9, 6},
                    {6, 7, 3, 4, 2, 9, 5, 1, 8},
                    {2, 9, 8, 5, 6, 1, 4, 3, 7},
                    {7, 6, 2, 9, 8, 4, 1, 5, 3},
                    {3, 8, 1, 2, 5, 7, 9, 6, 4},
                    {4, 5, 9, 6, 1, 3, 7, 8, 0}}};
    square response = findNextBox(board);
    square answer(8,8);
    EXPECT_EQ(response.row, answer.row);
    EXPECT_EQ(response.col, answer.col);
}

TEST(TestfindNextBox, coordinateSolve) {
    Board board = {{{5, 1, 7, 8, 3, 2, 6, 4, 9}, 
                    {9, 3, 6, 7, 4, 5, 8, 2, 1},
                    {8, 2, 4, 1, 9, 6, 3, 7, 5},
                    {1, 4, 5, 3, 7, 8, 2, 9, 6},
                    {6, 7, 3, 4, 2, 9, 5, 1, 8},
                    {2, 9, 8, 5, 6, 1, 4, 3, 7},
                    {7, 6, 2, 9, 8, 4, 1, 5, 3},
                    {3, 8, 1, 2, 5, 7, 9, 6, 4},
                    {4, 5, 9, 6, 1, 3, 7, 8, 2}}};
    square response = findNextBox(board);
    square answer(9,9);
    EXPECT_EQ(response.row, answer.row);
    EXPECT_EQ(response.col, answer.col);
}

TEST(TestIsValid, RowFalse) {
    Board board = {{{5, 1, 7, 8, 3, 2, 6, 4, 9}, 
                    {9, 3, 6, 7, 4, 5, 8, 2, 1},
                    {8, 2, 4, 1, 9, 6, 3, 7, 5},
                    {1, 4, 5, 3, 0, 8, 2, 9, 6}, //7
                    {6, 7, 3, 4, 2, 9, 5, 1, 8},
                    {2, 9, 8, 5, 6, 1, 4, 3, 7},
                    {7, 6, 2, 9, 8, 4, 1, 5, 3},
                    {3, 8, 1, 2, 5, 7, 9, 6, 4},
                    {4, 5, 9, 6, 1, 3, 7, 8, 2}}};
    size_t value = 9;
    square x(3,4);
    bool response = isValid(value, x, board);
    bool answer = false;
    EXPECT_EQ(response, answer);
}

TEST(TestIsValid, ColFalse) {
    Board board = {{{5, 1, 7, 8, 3, 2, 6, 4, 9}, 
                    {9, 3, 6, 7, 4, 5, 8, 2, 1},
                    {8, 2, 4, 1, 9, 6, 3, 7, 5},
                    {1, 4, 5, 3, 0, 8, 2, 0, 6}, //7
                    {6, 7, 3, 4, 2, 9, 5, 1, 8},
                    {2, 9, 8, 5, 6, 1, 4, 3, 7},
                    {7, 6, 2, 9, 8, 4, 1, 5, 3},
                    {3, 8, 1, 2, 5, 7, 9, 6, 4},
                    {4, 5, 9, 6, 1, 3, 7, 8, 2}}};
    size_t value = 9;
    square x(3,4);
    bool response = isValid(value, x, board);
    bool answer = false;
    EXPECT_EQ(response, answer);
}

TEST(TestIsValid, BoxFalse) {
    Board board = {{{5, 1, 7, 8, 3, 2, 6, 4, 9}, 
                    {9, 3, 6, 7, 4, 5, 8, 2, 1},
                    {8, 2, 4, 1, 0, 6, 3, 7, 5},
                    {1, 4, 5, 3, 0, 8, 2, 0, 6}, //7
                    {6, 7, 3, 4, 2, 9, 5, 1, 8},
                    {2, 9, 8, 5, 6, 1, 4, 3, 7},
                    {7, 6, 2, 9, 8, 4, 1, 5, 3},
                    {3, 8, 1, 2, 5, 7, 9, 6, 4},
                    {4, 5, 9, 6, 1, 3, 7, 8, 2}}};
    size_t value = 9;
    square x(3, 4);
    bool response = isValid(value, x, board);
    bool answer = false;
    EXPECT_EQ(response, answer);
}

TEST(TestIsValid, Valid) {
    Board board = {{{5, 1, 7,  8, 3, 2,  6, 4, 9}, 
                    {9, 3, 6,  7, 4, 5,  8, 2, 1},
                    {8, 2, 4,  1, 0, 6,  3, 7, 5},
                    {1, 4, 5,  3, 0, 8,  2, 0, 6}, //7
                    {6, 7, 3,  4, 2, 0,  5, 1, 8},
                    {2, 9, 8,  5, 6, 1,  4, 3, 7},
                    {7, 6, 2,  9, 8, 4,  1, 5, 3},
                    {3, 8, 1,  2, 5, 7,  9, 6, 4},
                    {4, 5, 9,  6, 1, 3,  7, 8, 2}}};
    size_t value = 9;
    square x(3,4);
    bool response = isValid(value, x, board);
    bool answer = true;
    EXPECT_EQ(response, answer);
}
