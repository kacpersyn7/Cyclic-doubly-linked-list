//
// Created by kacper on 09.01.17.
//

#include "Puzzle.h"


Puzzle::Puzzle(const char *answ, const char *init) {
    char * ptra = const_cast<char*>(answ);
    char * ptrb = const_cast<char*>(init);
    while(*ptra != '\0')
    {
        solution.insert(*ptra);
        puzzle.insert(*ptrb);
        ++ptra;
        ++ptrb;
    }
}

void Puzzle::shiftLeft() {
    char begin;
    puzzle.gotoBeginning();
    begin=puzzle.getCursor();
    char next;
    do 
    {	
	puzzle.gotoNext();
        next=puzzle.getCursor();
        puzzle.gotoPrior();
        puzzle.replace(next);
        
    } while (puzzle.gotoNext());
    puzzle.gotoEnd();
    puzzle.replace(begin);
}

void Puzzle::swapEnds() {
    char begin,end;

    puzzle.gotoBeginning();
    begin = puzzle.getCursor();
    puzzle.gotoEnd();

    end = puzzle.getCursor();
    puzzle.replace(begin);

    puzzle.gotoBeginning();
    puzzle.replace(end);
}

void Puzzle::display() {
    std::cout << "\n" << "Aktualne rozwiazanie: " << "\n";
    puzzle.showStructure();
    std::cout << "\n";
}

bool Puzzle::isSolved()
{
    puzzle.gotoBeginning();
    solution.gotoBeginning();
    do{
        if(puzzle.getCursor() != solution.getCursor()){
            puzzle.gotoBeginning();
            solution.gotoBeginning();
            return false;
        }
        solution.gotoNext();
    }
    while(puzzle.gotoNext());
    return  true;
}