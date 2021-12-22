#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <iomanip>

using namespace std;

class Player{
    
    private:
        int x, y, energy;
        bool treasure;
    
    public:
        static int dim;
        
        Player();
        void setEnergy(int i);
        int getEnergy();
        void incEnergy();
        void decEnergy();
        int getDim();
        static void setDim(int i);
        void setTreasure(bool b);
        bool getTreasure();
        void setX(int i);
        void setY(int i);
        int getX();
        int getY();
        void display(); //Banner with current coordinates and energy
};

#endif
