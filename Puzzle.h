//
// Created by kacper on 09.01.17.
//

#ifndef ZADANIE4_PUZZLE_H
#define ZADANIE4_PUZZLE_H
#include "MyList.h"
class Puzzle
{
public:
    Puzzle(const char *answ, const char *init);
    void shiftLeft();
    void swapEnds();
    void display();
    bool isSolved();
private:
    MyList<char> solution ;
    MyList<char> puzzle;
};

#endif //ZADANIE4_PUZZLE_H
