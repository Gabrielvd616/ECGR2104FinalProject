#include "Player.h"
#include <string>

//Player class definitions
Player::Player() {
    x = 5;
    y = 5;
    energy = 5;
    treasure = false;
}

void Player::setEnergy(int i) {energy = i;}
int Player::getEnergy() {return energy;}
void Player::incEnergy() {energy++;}
void Player::decEnergy() {energy--;}
int Player::getDim() {return dim;}
void Player::setDim(int i) {dim = i;}
void Player::setTreasure(bool b) {treasure = b;}
bool Player::getTreasure() {return treasure;}
void Player::setX(int i) {x = i;}
void Player::setY(int i) {y = i;}
int Player::getX() {return x;}
int Player::getY() {return y;}

void Player::display() {
    string title = "TREASURE HUNT";
    int width = (80 - title.length()) / 2;
    cout << setfill('-') << setw(80) << "" << endl;
    cout << setfill('-') << setw(width) << "" << title << setw(width + 1) << "" << endl;
    cout << setfill('-') << setw(80) << "" << endl;
    cout << "Your coordinates: " << y << " NORTH " << x << " EAST                                Energy level:" << setfill(' ') << setw(3) << energy << endl;
    cout << setfill('-') << setw(80) << "" << endl;
}

int Player::dim = 10;