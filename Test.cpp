#include "doctest.h"
#include "Direction.hpp"
#include "Board.hpp"

using namespace ariel;
using namespace std;

const string letters = "abcdefghijklmnopqrstuv";
const int SIZE = 22;

string rand_msg()
{
    string msg = "";
    int len = rand() % 50;
    for(int i = 0; i < len; i++)
        msg += letters.at(rand() % SIZE);

    return msg;
}

TEST_CASE("horizantal tests")
{
    Board board;
    string msg = "";
    for( int i = 0; i < 10; i++)
    {
        unsigned int row = rand() % 200;
        unsigned int colum = rand() % 200;
        msg = rand_msg();
        board.post(row,colum,Direction::Horizontal,msg);
        CHECK(board.read(row,colum,Direction::Horizontal,msg.length()) == msg);
    }
}

TEST_CASE("vertical tests")
{
    Board board;
    string msg = "";
    for( int i = 0; i < 10; i++)
    {
        unsigned int row = rand() % 200;
        unsigned int colum = rand() % 200;
        msg = rand_msg();
        board.post(row,colum,Direction::Vertical,msg);
        CHECK(board.read(row,colum,Direction::Vertical,msg.length()) == msg);
    }
}

TEST_CASE("empty board tests")
{
    Board board;
    for( int i = 0; i < 5; i++)
    {
        unsigned int row = rand() % 200;
        unsigned int colum = rand() % 200;
        CHECK(board.read(row,colum,Direction::Vertical,2) == "__");
        CHECK(board.read(row,colum,Direction::Horizontal,2) == "__");
    }
}

