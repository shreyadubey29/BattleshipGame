#include <iostream>
#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include "Play.h"

using namespace std;

int main()
{
    Human P1;       //Creating a human player
    Computer P2;    //Creating a computer player
    cout<<"The ships are represented in the following way :"<<endl;
    cout<<"Carrier = C\n"<<"Battleship = B\n"<<"Cruiser = K\n"<<"Submarine = S\n"<<"Destroyer = D\n";
    cout<<"=============================================================================="<<endl;
    cout<<"\nPlacing Ships for Player 1..."<<endl;
    P1.getInput();      //Setting the ships for human player
    cout<<endl;
    cout<<"\nPlacing Ships for Player 2..."<<endl;
    P2.getInput();      //Setting the ships for computer player
    cout<<"\nPlayer 2 ships are now set !"<<endl;
    cout<<"=============================================================================="<<endl;
    cout<<"Ready !!!"<<endl;
    cout<<"Now Let's Play !"<<endl;
    cout<<"------------------------------------------------------------------------------"<<endl;
    cout<<"You can enter the value 'Q' anytime to exit the game... "<<endl;
    cout<<"Please enter the location with the column alphabet and row number... "<<endl;
    Play(P1,P2);        //Starting the game with the human and computer player
    return 0;
}
