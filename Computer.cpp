#include "Computer.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include "Grid.h"

//Constructor for Computer class

Computer::Computer()
{
}

//Function to set ships for Computer

void Computer::getInput()
{
    string shipList[]={"Carrier","Battleship","Cruiser","Submarine","Destroyer"};
    string answer;
    int number;
    string column,row;
    string input1,input2;

    for(int i=0;i<5;i++)
       {
           if(randomInput(2)==0)
           {
               setOrientation('H');
           }
           else
           {
               setOrientation('V');
           }

           number=randomInput(10);
           column=65+number;
           stringstream row1;
           row1<<randomInput(10);
           row = row1.str();
           setShipType(shipList[i]);
           setLocationCell(column+row);

            if(validateLocation())
            {
                placeShip();
            }
            else
            {
                i--;
            }
       }
       cout<<"Do you wish to view Player 2 ship placements ? Please answer Y or N"<<endl;
        cin>>answer;
        if(answer=="y"||answer=="Y")
        {
            cout<<"The grid cells are numbered from 1 to 10 from top to bottom\n"<<endl;
            shipGrid.printGrid();
        }
}

//Function to print Target Grid

void Computer::printTargetGrid()
{
    targetGrid.printGrid();
}

//Function to print Ship location

void Computer::printShipGrid()
{
    shipGrid.printGrid();
}
