#include "Player.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//Constructor for Player class

Player::Player()
{
    setShipType("Carrier");
    setLocationCell("A1");
    setOrientation('V');
}

//Function to set the shipGrid

void Player::setShipGrid(int i, int j, char value)
{
    shipGrid.setGrid(i,j,value);
}

//Function to get the shipGrid

char Player::getShipGrid(int i, int j)
{
     char value=shipGrid.getGrid(i,j);
    return value;
}

//Function to get targetGrid

char Player::getTargetGrid(int i, int j)
{
    char value=targetGrid.getGrid(i,j);
    return value;
}

//Function to set targetGrid

void Player::setTargetGrid(int i,int j, char value)
{
    targetGrid.setGrid(i,j,value);
}

//Function to set Ship type

void Player::setShipType(string shipType)
{
    this->shipType=shipType;
}

//Function to get Ship type

string Player::getShipType()
{
    return shipType;
}

//Function to set orientation

void Player::setOrientation(char orientation)
{
    if(orientation=='V')
    {
       this->orientation="vertical";
    }
    if(orientation=='H')
    {
        this->orientation="horizontal";
    }

}

//Function to get orientation

string Player::getOrientation()
{
    return orientation;
}

//Function to set Location cell

void Player::setLocationCell(string locationCell)
{
    this->locationCell=locationCell;
}

//Function to get Location cell

string Player::getLocationCell()
{
    return locationCell;
}

// Function to generate random number

int Player::randomInput(int n)
{
    srand(time(NULL));
    int num=rand()%n;
    return num;
}

//Function to check if the location is valid

bool Player::validateLocation()
{
    int length;
    char column;
    string row;
    column=getLocationCell().at(0);
    int num1=(int)column-65;
    row=getLocationCell().substr(1);
    int num2=stoi(row)-1;
    int flag=0;
    if(num1<0||num1>9)
    {
        return false;
    }
    if(num2<0||num2>9)
    {
        return false;
    }
    if(shipType=="Carrier")
    {
            length=5;
            if(orientation=="horizontal")
            {
                if(num1+length<0||num1+length>9)
                {
                    return false;
                }
                for(int i=num1;i<num1+length;i++)
                {
                    if(shipGrid.getGrid(num2,i)!='-')
                    {
                        flag=flag+1;
                    }
                }
            }
            if(getOrientation()=="vertical")
            {
                if(num2+length<0||num2+length>9)
                {
                    return false;
                }
                for(int i=num2;i<num2+length;i++)
                {
                    if(shipGrid.getGrid(i,num1)!='-')
                    {
                        flag=flag+1;
                    }
                }
            }
            if(flag!=0)
            {
                return false;
            }
    }
    else if(shipType=="Battleship")
    {
            length=4;
            if(orientation=="horizontal")
            {
                if(num1+length<0||num1+length>9)
                {
                    return false;
                }
                for(int i=num1;i<num1+length;i++)
                {
                    if(shipGrid.getGrid(num2,i)!='-')
                    {
                        flag=flag+1;
                    }
                }
            }
            if(getOrientation()=="vertical")
            {
                if(num2+length<0||num2+length>9)
                {
                    return false;
                }
                for(int i=num2;i<num2+length;i++)
                {
                    if(shipGrid.getGrid(i,num1)!='-')
                    {
                        flag=flag+1;
                    }
                }
            }
            if(flag!=0)
            {
                return false;
            }
    }
    else if(shipType=="Cruiser")
    {
            length=3;
            if(orientation=="horizontal")
            {
                if(num1+length<0||num1+length>9)
                {
                    return false;
                }
                for(int i=num1;i<num1+length;i++)
                {
                    if(shipGrid.getGrid(num2,i)!='-')
                    {
                        flag=flag+1;
                    }
                }
            }
            if(getOrientation()=="vertical")
            {
                if(num2+length<0||num2+length>9)
                {
                    return false;
                }
                for(int i=num2;i<num2+length;i++)
                {
                    if(shipGrid.getGrid(i,num1)!='-')
                    {
                        flag=flag+1;
                    }
                }
            }
            if(flag!=0)
            {
                return false;
            }
    }
    else if(shipType=="Submarine")
    {
            length=3;
            if(orientation=="horizontal")
            {
                if(num1+length<0||num1+length>9)
                {
                    return false;
                }
                for(int i=num1;i<num1+length;i++)
                {
                    if(shipGrid.getGrid(num2,i)!='-')
                    {
                        flag=flag+1;
                    }
                }
            }
            if(getOrientation()=="vertical")
            {
                if(num2+length<0||num2+length>9)
                {
                    return false;
                }
                for(int i=num2;i<num2+length;i++)
                {
                    if(shipGrid.getGrid(i,num1)!='-')
                    {
                        flag=flag+1;
                    }
                }
            }
            if(flag!=0)
            {
                return false;
            }
    }
    else if(shipType=="Destroyer")
    {
            length=2;
            if(orientation=="horizontal")
            {
                if(num1+length<0||num1+length>9)
                {
                    return false;
                }
                for(int i=num1;i<num1+length;i++)
                {
                    if(shipGrid.getGrid(num2,i)!='-')
                    {
                        flag=flag+1;
                    }
                }
            }
            if(getOrientation()=="vertical")
            {
                if(num2+length<0||num2+length>9)
                {
                    return false;
                }
                for(int i=num2;i<num2+length;i++)
                {
                    if(shipGrid.getGrid(i,num1)!='-')
                    {
                        flag=flag+1;
                    }
                }
            }
            if(flag!=0)
            {
                return false;
            }
    }
    return true;
}

//Function to place ships on the grid ship

void Player::placeShip()
{
    int length;
    char column;
    string row;
    column=locationCell.at(0);
    int num1=(int)column-65;
    row=getLocationCell().substr(1);
    int num2=stoi(row)-1;
    if(getShipType()=="Carrier")
    {
        length=5;
        if(getOrientation()=="horizontal")
        {
            for(int i=num1;i<num1+length;i++)
            {
                shipGrid.setGrid(num2,i,'C');
            }
        }
        if(getOrientation()=="vertical")
        {
            for(int i=num2;i<num2+length;i++)
            {
                shipGrid.setGrid(i,num1,'C');
            }
        }
    }
    if(getShipType()=="Battleship")
    {
        length=4;
        if(getOrientation()=="horizontal")
        {
            for(int i=num1;i<num1+length;i++)
            {
                shipGrid.setGrid(num2,i,'B');
            }
        }
        if(getOrientation()=="vertical")
        {
            for(int i=num2;i<num2+length;i++)
            {
                shipGrid.setGrid(i,num1,'B');
            }
        }
    }
    if(getShipType()=="Cruiser")
    {
        length=3;
        if(getOrientation()=="horizontal")
        {
            for(int i=num1;i<num1+length;i++)
            {
                shipGrid.setGrid(num2,i,'K');
            }
        }
        if(getOrientation()=="vertical")
        {
            for(int i=num2;i<num2+length;i++)
            {
                shipGrid.setGrid(i,num1,'K');
            }
        }
    }
    if(getShipType()=="Submarine")
    {
        length=3;
        if(getOrientation()=="horizontal")
        {
            for(int i=num1;i<num1+length;i++)
            {
                shipGrid.setGrid(num2,i,'S');
            }
        }
        if(getOrientation()=="vertical")
        {
            for(int i=num2;i<num2+length;i++)
            {
                shipGrid.setGrid(i,num1,'S');
            }
        }
    }
    if(getShipType()=="Destroyer")
    {
        length=2;
        if(getOrientation()=="horizontal")
        {
            for(int i=num1;i<num1+length;i++)
            {
                shipGrid.setGrid(num2,i,'D');
            }
        }
        if(getOrientation()=="vertical")
        {
            for(int i=num2;i<num2+length;i++)
            {
                shipGrid.setGrid(i,num1,'D');
            }
        }
    }
}
