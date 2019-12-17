#include "Human.h"
#include "Player.h"
#include <iostream>
using namespace std;

//Constructor for the class Human

Human::Human()
{

}

bool Human::isShipPresent(string x)
{
    for(int i=0;i<ship_Symbol.size();i++)
    {
        if(ship_Symbol[i]==x)
        {
            return true;
        }
    }
    return false;
}

// Function to set Human player ships from the input file

void Human::getInput()
{
    string answer;
    ifstream file;
    string str;
    file.open("ship_placement.csv");     //Reading input from file

    if(!file.is_open())
    {
        cout<<"\nYour input file is not available. Please enter correct inputs and restart"<<endl;
        exit(1);
    }
    while(!file.eof())
    {
        getline(file,str,',');
        setShipType(str);

        getline(file,str,',');
        setLocationCell(str);

        getline(file,str);
        setOrientation(str.at(0));

        if(isShipPresent(getShipType()))
        {
            cout<<"\nYour input file has multiple ships of one kind. Please enter correct inputs and restart"<<endl;
            exit(1);
        }
        if(validateLocation())
        {
            ship_Symbol.push_back(getShipType());
            placeShip();
        }
        else
        {
            cout<<"\nYour input is invalid. Please enter correct inputs and restart"<<endl;
            exit(1);
        }

    }
        cout<<"Your ships are set"<<endl<<"Do you wish to view your ship placements ? Please answer Y or N"<<endl;
        cin>>answer;
        if(answer=="y"||answer=="Y")
        {
            cout<<"The grid cells are numbered from 1 to 10 from top to bottom\n"<<endl;
            shipGrid.printGrid();
        }
        file.close();
}

//Function to print Target ship of human player

void Human::printTargetGrid()
{
    targetGrid.printGrid();
}

//Function to print Ship position of Human player

void Human::printShipGrid()
{
    shipGrid.printGrid();
}
