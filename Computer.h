#ifndef COMPUTER_H
#define COMPUTER_H
#include "Player.h"
using namespace std;

class Computer : public Player
{
    public:
        Computer();
        void getInput();
        void printTargetGrid();
        void printShipGrid();

    private:
};

#endif // COMPUTER_H
