#ifndef HUMAN_H
#define HUMAN_H
#include "Player.h"
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

class Human: public Player
{
    public:
        Human();
        void getInput();
        void printTargetGrid();
        void printShipGrid();
        bool isShipPresent(string x);

    private:
        vector <string> ship_Symbol;
};

#endif // HUMAN_H
