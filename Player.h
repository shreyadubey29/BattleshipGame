#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "Grid.h"
using namespace std;

class Player
{
    public:
        Player();
        void setShipGrid(int i, int j, char value);
        char getShipGrid(int i, int j);
        char getTargetGrid(int i, int j);
        void setTargetGrid(int i,int j, char value);
        void setShipType(string shipType);
        string getShipType();
        void setOrientation(char orientation);
        string getOrientation();
        void setLocationCell(string locationCell);
        string getLocationCell();
        virtual void getInput()=0;
        bool validateLocation();
        void placeShip();
        int randomInput(int n);
        virtual void printTargetGrid()=0;
        virtual void printShipGrid()=0;

    protected:
        Grid targetGrid;
        Grid shipGrid;
        string shipType;
        string orientation;
        string locationCell;
};

#endif // PLAYER_H
