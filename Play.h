#ifndef PLAY_H
#define PLAY_H
#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include <vector>
class Play
{
    public:
        Play(Human P1, Computer P2);
        void setScore(int i,int value);
        int getScore(int i);
        void launch();
        char ifHit(string torpedo, int count);
        void modifyGrid(char shipHit,int counter);
        void calculateScore();
        int randomInput(int n);
        bool validateTorpedo(string torpedo,int count);

    private:
        Human P1;
        Computer P2;
        vector<int> score;
};

#endif // PLAY_H
