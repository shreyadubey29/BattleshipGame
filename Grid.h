#ifndef GRID_H
#define GRID_H

using namespace std;

class Grid
{
    public:
        Grid();
        char getGrid(int i, int j);
        void setGrid(int i,int j, char value);
        void printGrid();

    private:
        char grid[10][10];
};

#endif // GRID_H
