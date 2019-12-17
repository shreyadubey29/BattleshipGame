#include "Grid.h"
#include <iostream>

//Constructor for Grid class

Grid::Grid()
{
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
        {
               grid[i][j]='-';
        }
}

//Function to get Grid value

char Grid::getGrid(int i, int j)
{
    char value=grid[i][j];
    return value;
}

//Function to set Grid value

void Grid::setGrid(int i,int j, char value)
{
     grid[i][j]=value;
}

//Function to print Grid

void Grid::printGrid()
{
    char a;
    cout<<" \t";
    for(int k=0;k<10;k++)
    {
        a=65+k;
        cout<<a<<"   ";
    }
    cout<<endl<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<" "<<i+1<<"\t";
        for(int j=0;j<10;j++)
        {
            cout<<getGrid(i,j)<<"   ";
        }
        cout<<endl;
    }

}
