#include <iostream>
#include "Puzzle.h"

char menu();

int main()
{

    try{

        char ch;
        Puzzle p("aaaab","aabab");

        ch = menu();
        while(ch != 'Q' && ch != 'q')
        {
            ch = tolower(ch);
            switch(ch)
            {
                case 's':  if(p.isSolved())
                        std::cout<<"Rozwiazano!\n";
                    else
                        std::cout<<"Nie rozwiazano!\n";
                    break;
                case 'z':   p.swapEnds();
                    break;
                case 'd':   p.display();
                    break;
                case 'r':
                    //p.reversePuzzle();
                    break;

                case '<':   p.shiftLeft();
                    break;
            }
            if(ch=='z'||ch=='<'||ch=='r')
            {
                if(p.isSolved())
                   std::cout<<"Hura!\tRozwiazano!\n";
                p.display();
            }

            ch=menu();
        }
        p.display();

    }
    catch (std::bad_alloc & ba) {
        std::cerr<<ba.what()<<"\n";
    }
    catch (std::logic_error & lo) {
        std::cerr<<lo.what()<<"\n";//exit(EXIT_FAILURE);
    }
    return 0;
}

char menu()
{
    std::cout   <<"\n************************************\n"
                <<"\"s\" - sprawdza poprawnosc rozwiazania\n"
                <<"\"z\" - zamienia krancowe litery\n"
                <<"\"<\" - przysuwa wszystkie litery w lewo\n"
                <<"\"d\" - wyswietla utworzone puzle\n"
                <<"\"r\" - zamienie kolejnosc wszystkich liter\n"
                <<"\"q\" - konczy dialanie programu\n\n"
                <<"Wybierz zadanie: ";
    char ch=std::cin.get();
    while(std::cin.get()!='\n')
        continue;

    std::cout   <<"************************************\n\n";
    return ch;
}
