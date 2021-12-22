#ifndef TREASURE_H
#define TREASURE_H
#include <iostream>
#include <string>
#include <random>
#include "Player.h"
#include "Land.h"

using namespace std;

//Empty Class declarations
class Player;

//Game Engine functions
void clearscreen();
void instruction();
void startBanner();
int mapSelect();
void gameEngine(Player&);

#endif
