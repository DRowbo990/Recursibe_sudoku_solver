
#include <gtest/gtest.h>

#include "Sudoku.hpp"

TEST(SudokuTest, findfindNextBox)
{
    Board board = { {{0, 0, 0, 0, 3, 0, 6, 4, 0},
                  {0, 3, 0, 7, 0, 5, 8, 0, 0},
                  {8, 2, 0, 0, 9, 6, 0, 7, 0},
                  {0, 0, 0, 0, 7, 0, 2, 9, 6},
                  {0, 0, 3, 4, 2, 9, 0, 1, 0},
                  {2, 9, 8, 5, 6, 1, 4, 0, 7},
                  {7, 0, 2, 9, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0, 0, 6, 4},
                  {4, 5, 9, 0, 0, 0, 7, 0, 0}} };
    square response = findNextBox(board);
    square expected(0,0);

    EXPECT_EQ(response.row, expected.row);
    EXPECT_EQ(response.col, expected.col);

    Board board1 = { {{8, 3, 0, 0, 0, 0, 1, 0, 2},
                  {1, 0, 7, 3, 0, 8, 0, 0, 0},
                  {0, 0, 0, 5, 1, 0, 3, 0, 0},
                  {0, 0, 0, 0, 0, 4, 0, 0, 0},
                  {4, 5, 6, 2, 8, 3, 0, 0, 0},
                  {0, 0, 0, 0, 0, 5, 0, 6, 4},
                  {7, 0, 0, 0, 0, 0, 4, 0, 0},
                  {0, 9, 4, 0, 3, 1, 6, 0, 0},
                  {3, 0, 2, 4, 0, 0, 0, 0, 5}} };
    square response1 = findNextBox(board1);
    square expected1(0, 2);

    EXPECT_EQ(response1.row, expected1.row);
    EXPECT_EQ(response1.col, expected1.col);

    Board board2 = { {{8, 3, 5, 6, 4, 9, 1, 7, 2},
                   {1, 4, 7, 3, 2, 8, 5, 9, 6},
                   {6, 2, 9, 5, 1, 7, 3, 4, 8},
                   {9, 8, 1, 7, 6, 4, 2, 5, 3},
                   {4, 5, 6, 2, 8, 3, 7, 1, 9},
                   {2, 7, 3, 1, 9, 5, 8, 6, 4},
                   {7, 6, 8, 9, 5, 2, 4, 3, 1},
                   {5, 9, 4, 8, 3, 1, 6, 2, 7},
                   {3, 1, 2, 4, 7, 6, 9, 8, 5}} };

    square response2 = findNextBox(board2);
    square expected2(9, 9);

    EXPECT_EQ(response2.row, expected2.row);
    EXPECT_EQ(response2.col, expected2.col);
}

TEST(SudokuTest, isValid)
{
    Board board = { {{0, 0, 0, 0, 3, 0, 6, 4, 0},
                  {0, 3, 0, 7, 0, 5, 8, 0, 0},
                  {8, 2, 0, 0, 9, 6, 0, 7, 0},
                  {0, 0, 0, 0, 7, 0, 2, 9, 6},
                  {0, 0, 3, 4, 2, 9, 0, 1, 0},
                  {2, 9, 8, 5, 6, 1, 4, 0, 7},
                  {7, 0, 2, 9, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0, 0, 6, 4},
                  {4, 5, 9, 0, 0, 0, 7, 0, 0}} };
    square response = findNextBox(board);
    square expected;
    size_t value = 1;
    
    ASSERT_TRUE(isValid(value, response, board));

    Board board1 = { {{0, 0, 0, 0, 3, 0, 6, 4, 0},
                 {0, 3, 0, 7, 0, 5, 8, 0, 0},
                 {1, 2, 0, 0, 9, 6, 0, 7, 0},
                 {0, 0, 0, 0, 7, 0, 2, 9, 6},
                 {0, 0, 3, 4, 2, 9, 0, 1, 0},
                 {2, 9, 8, 5, 6, 1, 4, 0, 7},
                 {7, 0, 2, 9, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 6, 4},
                 {4, 5, 9, 0, 0, 0, 7, 0, 0}} };
    square response1 = findNextBox(board1);
    square expected1;
    size_t value1 = 1;

    ASSERT_FALSE(isValid(value1, response1, board1));
    
    Board board2 = { {{0, 0, 0, 1, 3, 0, 6, 4, 0},
                 {0, 3, 0, 7, 0, 5, 8, 0, 0},
                 {8, 2, 0, 0, 9, 6, 0, 7, 0},
                 {0, 0, 0, 0, 7, 0, 2, 9, 6},
                 {0, 0, 3, 4, 2, 9, 0, 1, 0},
                 {2, 9, 8, 5, 6, 1, 4, 0, 7},
                 {7, 0, 2, 9, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 6, 4},
                 {4, 5, 9, 0, 0, 0, 7, 0, 0}} };
    square response2 = findNextBox(board2);
    square expected2;
    size_t value2 = 1;

    ASSERT_FALSE(isValid(value2, response2, board2));

    Board board3 = { {{5, 1, 7, 8, 3, 0, 6, 4, 0},
                {0, 3, 0, 7, 0, 5, 8, 0, 0},
                {8, 2, 0, 0, 9, 6, 0, 7, 0},
                {0, 0, 0, 0, 7, 0, 2, 9, 6},
                {0, 0, 3, 4, 2, 9, 0, 1, 0},
                {2, 9, 8, 5, 6, 1, 4, 0, 7},
                {7, 0, 2, 9, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 6, 4},
                {4, 5, 9, 0, 0, 0, 7, 0, 0}} };

    square response3 = findNextBox(board3);
    square expected3;
    size_t value3 = 2;

    ASSERT_TRUE(isValid(value3, response3, board3));

    Board board4 = { {{5, 1, 7, 8, 3, 0, 6, 4, 0},
               {0, 3, 0, 7, 0, 5, 8, 0, 0},
               {8, 2, 0, 0, 9, 6, 0, 7, 0},
               {0, 0, 0, 0, 7, 0, 2, 9, 6},
               {0, 0, 3, 4, 2, 9, 0, 1, 0},
               {2, 9, 8, 5, 6, 1, 4, 0, 7},
               {7, 0, 2, 9, 0, 0, 0, 0, 0},
               {0, 0, 0, 0, 0, 0, 0, 6, 4},
               {4, 5, 9, 0, 0, 0, 7, 0, 0}} };

    
    square response4 = findNextBox(board4);
    square expected4;
    size_t value4 = 7;
  
    ASSERT_FALSE(isValid(value4, response4, board4));

    Board board5 = { {{5, 1, 7, 8, 3, 2, 6, 4, },
               {9, 3, 0, 7, 0, 5, 8, 0, 0},
               {8, 2, 0, 0, 9, 6, 0, 7, 0},
               {0, 0, 0, 0, 7, 0, 2, 9, 6},
               {0, 0, 3, 4, 2, 9, 0, 1, 0},
               {2, 9, 8, 5, 6, 1, 4, 0, 7},
               {7, 0, 2, 9, 0, 0, 0, 0, 0},
               {0, 0, 0, 0, 0, 0, 0, 6, 4},
               {4, 5, 9, 0, 0, 0, 7, 0, 0}} };

    square response5 = findNextBox(board5);

    size_t value5 = 6;

    ASSERT_FALSE(isValid(value5, response5, board5));

    Board answer6 = { {{5, 1, 7, 8, 3, 2, 6, 4, 9},
                   {9, 3, 6, 7, 4, 5, 8, 2, 1},
                   {8, 2, 4, 1, 9, 6, 3, 7, 5},
                   {1, 4, 5, 3, 7, 8, 2, 9, 6},
                   {6, 7, 3, 4, 2, 9, 5, 1, 8},
                   {2, 9, 8, 5, 6, 1, 4, 3, 7},
                   {7, 6, 2, 9, 8, 4, 1, 5, 3},
                   {3, 8, 1, 2, 5, 7, 9, 6, 4},
                   {4, 5, 9, 6, 1, 3, 7, 8, 2}} };
    square response6 = findNextBox(answer6);
    square expected6(9, 9);

    EXPECT_EQ(response6.row, expected6.row);
}

TEST(SudokuTest, boxTest)
{
    Board board = { {{5, 1, 7, 8, 3, 2, 6, 4, 9},
                   {9, 0, 6, 7, 4, 5, 8, 2, 1},
                   {8, 2, 4, 1, 9, 6, 3, 7, 5},
                   {1, 4, 5, 3, 7, 8, 2, 9, 6},
                   {6, 7, 3, 4, 2, 9, 5, 1, 8},
                   {2, 9, 8, 5, 6, 1, 4, 3, 7},
                   {7, 6, 2, 9, 8, 4, 1, 5, 3},
                   {3, 8, 1, 2, 5, 7, 9, 6, 4},
                   {4, 5, 9, 6, 1, 3, 7, 8, 2}} };
    square response = findNextBox(board);

    size_t value = 3;
    ASSERT_TRUE(isValid(value, response, board));

    Board board1 = { {{5, 1, 7, 8, 3, 2, 6, 4, 9},
                   {9, 0, 6, 7, 4, 5, 8, 2, 1},
                   {8, 2, 4, 1, 9, 6, 3, 7, 5},
                   {1, 4, 5, 3, 7, 8, 2, 9, 6},
                   {6, 7, 3, 4, 2, 9, 5, 1, 8},
                   {2, 9, 8, 5, 6, 1, 4, 3, 7},
                   {7, 6, 2, 9, 8, 4, 1, 5, 3},
                   {3, 8, 1, 2, 5, 7, 9, 6, 4},
                   {4, 5, 9, 6, 1, 3, 7, 8, 2}} };
    square response1 = findNextBox(board1);

    size_t value1 = 4;
    ASSERT_FALSE(isValid(value1, response1, board1));

    Board board2 = { {{5, 1, 7, 8, 3, 2, 6, 4, 9},
                   {9, 0, 6, 7, 0, 5, 8, 2, 1},
                   {8, 2, 4, 1, 9, 6, 3, 7, 5},
                   {1, 0, 5, 3, 7, 8, 2, 9, 6},
                   {6, 7, 3, 4, 2, 9, 5, 1, 8},
                   {2, 9, 8, 5, 6, 1, 4, 3, 7},
                   {7, 6, 2, 9, 8, 4, 1, 5, 3},
                   {3, 8, 1, 2, 5, 7, 9, 6, 4},
                   {4, 5, 9, 6, 1, 3, 7, 8, 2}} };
    square response2 = findNextBox(board2);

    size_t value2 = 4;
    ASSERT_FALSE(isValid(value2, response2, board2));

    Board board3 = { {{5, 1, 7, 8, 3, 2, 6, 4, 9},
                   {9, 0, 6, 7, 4, 5, 8, 2, 1},
                   {8, 2, 4, 1, 9, 6, 3, 7, 5},
                   {1, 4, 5, 3, 7, 8, 2, 9, 6},
                   {6, 7, 3, 4, 2, 9, 5, 1, 8},
                   {2, 9, 8, 5, 6, 1, 4, 3, 7},
                   {7, 6, 2, 9, 8, 4, 1, 5, 3},
                   {3, 8, 1, 2, 5, 7, 9, 6, 4},
                   {4, 5, 9, 6, 1, 3, 7, 8, 2}} };
    square response3 = findNextBox(board3);

    size_t value3 = 3;
    ASSERT_TRUE(isValid(value3, response3, board3));
}

TEST(SudokuTest, isValidCol)
{
    Board board = { {{5, 1, 7, 8, 3, 2, 6, 4, 9},
                   {9, 3, 6, 7, 4, 5, 8, 2, 1},
                   {8, 2, 4, 1, 0, 6, 3, 7, 5},
                   {1, 4, 5, 3, 7, 8, 2, 9, 6},
                   {6, 7, 3, 4, 2, 9, 5, 1, 8},
                   {2, 9, 8, 5, 6, 1, 4, 3, 7},
                   {7, 6, 2, 9, 8, 4, 1, 5, 3},
                   {3, 8, 1, 2, 5, 7, 9, 6, 4},
                   {4, 5, 9, 6, 1, 3, 7, 8, 2}} };
    square response = findNextBox(board);

    size_t value3 = 5;
    ASSERT_FALSE(isValid(value3, response, board));

    Board board1 = { {{5, 1, 7, 8, 3, 2, 6, 4, 9},
                   {9, 3, 6, 7, 4, 5, 8, 2, 1},
                   {8, 2, 4, 1, 0, 6, 3, 7, 5},
                   {1, 4, 5, 3, 7, 8, 2, 9, 6},
                   {6, 7, 3, 4, 2, 9, 5, 1, 8},
                   {2, 9, 8, 5, 6, 1, 4, 3, 7},
                   {7, 6, 2, 9, 8, 4, 1, 5, 3},
                   {3, 8, 1, 2, 5, 7, 9, 6, 4},
                   {4, 5, 9, 6, 1, 3, 7, 8, 2}} };
    square response1 = findNextBox(board);
    size_t value1 = 9;
    ASSERT_TRUE(isValid(value1, response1, board1));
}

TEST(SudokuTest, isValidRow)
{
    Board board = { {{5, 1, 7, 8, 3, 2, 6, 4, 9},
                   {9, 3, 6, 7, 4, 5, 8, 2, 1},
                   {8, 2, 4, 1, 0, 6, 3, 7, 5},
                   {1, 4, 5, 0, 7, 8, 2, 9, 6},
                   {6, 7, 3, 4, 2, 9, 5, 1, 8},
                   {2, 9, 8, 5, 0, 1, 4, 3, 7},
                   {7, 6, 2, 9, 8, 4, 1, 5, 3},
                   {3, 8, 1, 2, 5, 7, 9, 6, 4},
                   {4, 5, 9, 6, 1, 3, 7, 8, 2}} };
    square response = findNextBox(board);

    size_t value3 = 3;
    ASSERT_FALSE(isValid(value3, response, board));
}

TEST(SudokuTest, isValidBox)
{
    Board board = { {{5, 1, 7, 8, 3, 2, 6, 4, 9},
                   {9, 3, 6, 7, 4, 5, 8, 2, 1},
                   {8, 2, 4, 1, 0, 6, 3, 0, 5},
                   {1, 4, 5, 3, 0, 8, 2, 9, 6},
                   {6, 7, 3, 4, 2, 9, 5, 1, 8},
                   {2, 9, 8, 5, 6, 1, 4, 3, 7},
                   {7, 6, 2, 9, 8, 4, 1, 5, 3},
                   {3, 8, 1, 2, 5, 7, 9, 6, 4},
                   {4, 5, 9, 6, 1, 3, 7, 8, 2}} };

    square response = findNextBox(board);

    size_t value3 = 7;
    ASSERT_FALSE(isValid(value3, response, board));
}

TEST(SudokuTest, solvedBoard)
{
    Board answer = { {{5, 1, 7, 8, 3, 2, 6, 4, 9},
                   {9, 3, 6, 7, 4, 5, 8, 2, 1},
                   {8, 2, 4, 1, 9, 6, 3, 7, 5},
                   {1, 4, 5, 3, 7, 8, 2, 9, 6},
                   {6, 7, 3, 4, 2, 9, 5, 1, 8},
                   {2, 9, 8, 5, 6, 1, 4, 3, 7},
                   {7, 6, 2, 9, 8, 4, 1, 5, 3},
                   {3, 8, 1, 2, 5, 7, 9, 6, 4},
                   {4, 5, 9, 6, 1, 3, 7, 8, 2}} };

    square end = findNextBox(answer);
    EXPECT_EQ(end.row, 9);
    EXPECT_EQ(end.col, 9);
}