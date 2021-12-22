#include "treasure.h"
#include "unistd.h"

//g++ Land.h treasure.h treasure.cpp Player.h Player.cpp gameEngine.cpp -o treasure -std=c++11

int main(void){
    
    startBanner();
    instruction();
    int choice = mapSelect();
    Player::setDim(choice);
    Player so;
    gameEngine(so);
    
	return 0;
}

void clearscreen() {
    char i = getchar();
    cout << "\033[2J\033[1;1H";
}

void instruction() {
    string gName = "TREASURE HUNT";
    int len = (80 - gName.length()) / 2; //80 is the number of columns to display
    cout << setfill('-') << setw(80) << "" << endl << setfill(' ') << setfill('*') << setw(len) << "" << gName << setfill('*') << setw(len + 1) << "" << endl << setfill('-') << setw(80) << "" << endl << setfill(' ') << endl;
    cout << "This is a text based game which takes character input\nYour goal is to find the treasure before you run out of energy\nYou start with 5 energy points from the middle of the map\nNavigate to any of the four directions in the map on every turn\nOnce the game starts you can quit the game by pressing Q" << endl << setfill('*') << setw(25) << "" << "GOOD LUCK!!!" << setfill('*') << setw(25) << "" << setfill(' ');
    clearscreen();
}

void startBanner() {
    cout << "\033[2J\033[1;1H";
    cout << "************** $$$$$$$$            $$     $$            $$$$$$$$ **************\n**************    $$               $$     $$            $$       **************\n**************    $$               $$$$$$$$$            $$$$$$$$ **************\n**************    $$               $$     $$            $$       **************\n**************    $$               $$     $$            $$$$$$$$ **************\n*******************************************************************************\n*******************************************************************************\n*****$$     $$          $$      $$          $$      $$          $$$$$$$$$$$****\n*****$$     $$          $$      $$          $$$$    $$               $$    ****\n*****$$$$$$$$$          $$      $$          $$  $$  $$               $$    ****\n*****$$     $$          $$      $$          $$    $$$$               $$    ****\n*****$$     $$          $$$$$$$$$$          $$      $$               $$    ****\n*******************************************************************************\n****************************** /\\____;;___\\ ***********************************\n****************************** | /        / ***********************************\n******************************  \\'. $ $$$'. ***********************************\n******************************* |\\$$ $ $$  \\ **********************************\n******************************* | |---------| *********************************\n******************************* \\ | TREASURE| *********************************\n*******************************  \\|_________| *********************************\n****************************LET THE ADVENTURE BEGIN****************************\n*******************************************************************************" << endl;
    usleep(3000000);
    cout << "\033[2J\033[1;1H";
}

int mapSelect() {
    int mapSize = 10;
    
    cout << "Select the size of the map\nDefault is " << mapSize << "x" << mapSize << "\nMax dimension is 50x50\n";
    cin >> mapSize;
    
    if(mapSize < 10)
        mapSize = 10;
    else if(mapSize > 50)
        mapSize = 50;
    
    cout << "\033[2J\033[1;1H";
    
    return mapSize;
}