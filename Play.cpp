#include "Play.h"
#include "Player.h"
#include <iostream>
#include "Grid.h"
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>

using namespace std;

// Constructor of the class Play

Play::Play(Human P1, Computer P2)
{
    score.push_back(1);
    score.push_back(1);
    setScore(0,0);
    setScore(1,0);
    this->P1=P1;
    this->P2=P2;
    launch();
}

//Function for launching the torpedo

void Play::launch()
{
    calculateScore();
    string torpedo;
    int count=1;
    char shipHit;
    string shipType;
    while(getScore(0)<17&&getScore(1)<17)
    {
        if(count==1||count%2==1)
        {
            cout<<endl<<"Your turn "<<endl;
            if(count==1)
            {
                cout<<"Your Target Grid ->\n"<<endl;
                P2.printTargetGrid();
            }
            cout<<"Where do you want to drop the torpedo :";
            cin>>torpedo;
            if(torpedo=="Q")
            {
                cout<<"------------------------------------------------------------------------------"<<endl;
                cout<<"Game Over !!!"<<endl;
                cout<<"Computer's target grid ->\n"<<endl;
                P2.printTargetGrid();
                cout<<"Computer's Ships Position ->\n"<<endl;
                P2.printShipGrid();
                calculateScore();
                cout<<"Your score :"<<getScore(0)<<"||"<<" Computer's score :"<<getScore(1)<<endl;
                cout<<"------------------------------------------------------------------------------"<<endl;
                exit(1);
            }
            else
            {
                if(validateTorpedo(torpedo,count))
                {
                    shipHit=ifHit(torpedo,count);
                    if(shipHit!='N')
                    {
                        switch(shipHit)
                        {
                            case 'C': shipType="Carrier";
                                    break;
                            case 'B': shipType="Battleship";
                                    break;
                            case 'K': shipType="Cruiser";
                                    break;
                            case 'S': shipType="Submarine";
                                    break;
                            case 'D': shipType="Destroyer";
                        }
                        cout<<endl<<"BOOM!!!\n"<<endl;
                        cout<<"You sunk Computer's "<<shipType<<" !"<<endl;
                        modifyGrid(shipHit,count);
                        calculateScore();
                        cout<<"Your Target Grid ->\n"<<endl;
                        P2.printTargetGrid();
                        cout<<endl<<"Your score :"<<getScore(0)<<" ||"<<" Computer's score :"<<getScore(1)<<endl;
                        cout<<"------------------------------------------------------------------------------"<<endl;
                    }
                    else
                    {
                        cout<<"You Missed !"<<endl;
                        calculateScore();
                        cout<<"Your Target Grid ->\n"<<endl;
                        P2.printTargetGrid();
                        cout<<endl<<"Your score :"<<getScore(0)<<" ||"<<" Computer's score :"<<getScore(1)<<endl;
                        cout<<"------------------------------------------------------------------------------"<<endl;
                    }
                }
                else
                {
                    continue;
                }
            }
        }
        else
        {
            int number=randomInput(10);
            char column1=65+number;
            string column(1,column1);
            stringstream row1;
            row1<<randomInput(10)+1;
            string row = row1.str();
            torpedo=column+row;
            if(validateTorpedo(torpedo,count))
            {
                cout<<endl<<"Computer's turn \n"<<endl;
                cout<<"Computer hits torpedo on :"<<torpedo<<endl;
                shipHit=ifHit(torpedo,count);
                if(shipHit!='N')
                {
                    switch(shipHit)
                    {
                        case 'C': shipType="Carrier";
                                break;
                        case 'B': shipType="Battleship";
                                break;
                        case 'K': shipType="Cruiser";
                                break;
                        case 'S': shipType="Submarine";
                                break;
                        case 'D': shipType="Destroyer";
                    }
                    cout<<endl<<"BOOM!!!\n"<<endl;
                    cout<<"Your "<<shipType<<" has sunk !"<<endl;
                    modifyGrid(shipHit,count);
                    calculateScore();
                    cout<<"Computer's Target Grid ->\n"<<endl;
                    P1.printTargetGrid();
                    string f;
                    cout<<"\nDo you wish to see your ships? enter Y or N\n";
                    cin>>f;
                    if(f=="Y"||f=="y")
                    {
                        cout<<"\nYour ships ->\n"<<endl;
                        P1.printShipGrid();
                    }
                    cout<<endl<<"Your score :"<<getScore(0)<<" ||"<<" Computer's score :"<<getScore(1)<<endl;
                    cout<<"------------------------------------------------------------------------------"<<endl;
                }
                else
                {
                    cout<<"Computer Missed !"<<endl;
                    calculateScore();
                    cout<<"Computer's Target Grid ->\n"<<endl;
                    P1.printTargetGrid();
                    cout<<endl<<"Your score :"<<getScore(0)<<" ||"<<" Computer's score :"<<getScore(1)<<endl;
                    cout<<"------------------------------------------------------------------------------"<<endl;
                }
            }
            else
            {
                continue;
            }
        }
        count++;
    }
    cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
    if(getScore(0)>getScore(1))
    {
        cout<<endl<<"You win !"<<endl;
    }
    else
    {
        cout<<endl<<"The Computer won !"<<endl;
    }
    cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
}

// Function to generate random torpedo for Computer

int Play::randomInput(int n)
{
   // srand(time(NULL));
    int num=(rand()+7)%n;
    return num;
}

//Function to check if the torpedo has hit a ship

char Play::ifHit(string torpedo, int count)
{
    char column;
    string row;
    column=torpedo.at(0);
    int num1=(int)column-65;
    row=torpedo.substr(1);
    int num2=stoi(row)-1;
    if(count==1||count%2==1)
    {
        if(P2.getShipGrid(num2,num1)=='-')
        {
            P2.setShipGrid(num2,num1,'X');
            P2.setTargetGrid(num2,num1,'X');
            return 'N';
        }
        else
        {
            return P2.getShipGrid(num2,num1);
        }
    }
    else
    {
        if(P1.getShipGrid(num2,num1)=='-')
        {
           P1.setShipGrid(num2,num1,'X');
           P1.setTargetGrid(num2,num1,'X');
            return 'N';
        }
        else
        {
            return P1.getShipGrid(num2,num1);
        }
    }
}

// Function to modify grid

void Play::modifyGrid(char shipHit,int counter)
{
    if(counter==1||counter%2==1)
    {
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(P2.getShipGrid(i,j)==shipHit)
                {
                    P2.setShipGrid(i,j,'O');
                    P2.setTargetGrid(i,j,'O');
                }
            }
        }
    }
    else
    {
         for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(P1.getShipGrid(i,j)==shipHit)
                {
                    P1.setShipGrid(i,j,'O');
                    P1.setTargetGrid(i,j,'O');
                }
            }
        }
    }
}

//Function to calculate score

void Play::calculateScore()
{
    int score1=0;
    int score2=0;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(P2.getTargetGrid(i,j)=='O')
            {
                score1++;
            }
            if(P1.getTargetGrid(i,j)=='O')
            {
                score2++;
            }
        }
    }
    setScore(0,score1);
    setScore(1,score2);
}

//Function to set score

void Play::setScore(int i,int value)
{
    score[i]=value;
}

//Function to get score

int Play::getScore(int i)
{
    return score[i];
}

// Function to validate the torpedo

bool Play::validateTorpedo(string torpedo, int count)
{
    if(torpedo.length()<2)
    {
        cout<<endl<<"Input invalid ! "<<endl;
        return false;
    }
    char column;
    string row;
    column=torpedo.at(0);
    int num1=(int)column-65;
    row=torpedo.substr(1);
    int num2=stoi(row)-1;
    if(count==1||count%2==1)
    {
        if(num1<0||num1>9)
        {
            cout<<endl<<"Don't hit out of the grid ! "<<endl;
            return false;
        }
        else if(num2<0||num2>9)
        {
            cout<<endl<<"Don't hit out of the grid ! "<<endl;
            return false;
        }
        else if(P2.getShipGrid(num2,num1)=='X')
        {
            cout<<endl<<"You already hit this location !"<<endl;
            return false;
        }
        else if(P2.getShipGrid(num2,num1)=='O')
        {
            cout<<endl<<"You already sunk this ship !"<<endl;
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        if(P1.getShipGrid(num2,num1)=='X')
        {
            return false;
        }
        else if(P1.getShipGrid(num2,num1)=='O')
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}
