#include "treasure.h"
#include "unistd.h"

using namespace std;

void gameEngine(Player& p) {
    //Generates a PRNG
    random_device dev; //generator
    mt19937 twist(dev());
    uniform_int_distribution<size_t> u(0, p.getDim() - 1); //distributor
    
    int mapDim = p.getDim();
    //Uses a PRNG (Pseudo Random Number Generator) to generate the map
    Land* map[p.getDim()][p.getDim()];
    
    for(int i = 0; i < p.getDim(); i++) {
        for(int j = 0; j <p.getDim(); j++) {
            switch(u(twist) % 4) {
                case 0:
                    map[i][j] = new Forest;
                    break;
                case 1:
                    map[i][j] = new Orchard;
                    break;
                case 2:
                    map[i][j] = new Desert;
                    break;
                case 3:
                    map[i][j] = new Lake;
                    break;
            }
        }
    }
    
    int xPlay = p.getX(), yPlay = p.getY();
    
    while((xPlay == p.getX()) && (yPlay == p.getY())) {
        xPlay = u(twist);
        yPlay = u(twist);
    }
    delete map[xPlay][yPlay];
    map[xPlay][yPlay] = new Ruins;
    
    map[p.getX()][p.getY()]->setVisit();
    char input;
    
    do {
        p.display();
        for(int i = 0; i < p.getDim() + 1; i++)
            cout << "* ";
        cout << "*\n";
        for(int i = 0; i < p.getDim(); i++) {
            cout << "*";
            for(int j = 0; j < p.getDim(); j++) {
                if(map[j][p.getDim() - i - 1]->getVisit())
                    cout << " +";
                else
                    cout << "  ";
            }
            cout << " *\n";
        }
        for(int i = 0; i < p.getDim() + 1; i++)
            cout << "* ";
        cout << "*\n";
        
        if(p.getY() == p.getDim() - 1)
            cout << "You are on the north end and you see nothing." << endl;
        else
            cout << "To the north you see " << map[p.getX()][p.getY() + 1]->description() << "." << endl;
        
        if(p.getY() == 0)
            cout << "You are on the south end and you see nothing." << endl;
        else
            cout << "To the south you see " << map[p.getX()][p.getY() - 1]->description() << "." << endl;
        
        if(p.getX() == p.getDim() - 1)
            cout << "You are on the east end and you see nothing." << endl;
        else
            cout << "To the east you see " << map[p.getX() + 1][p.getY()]->description() << "." << endl;
        
        if(p.getX() == 0)
            cout << "You are on the west end and you see nothing." << endl;
        else
            cout << "To the west you see " << map[p.getX() - 1][p.getY()]->description() << "." << endl;
        
        cout << "In which direction would you like to go?\nSelect:\tN for north\tS for south\tE for east\tW for west" << endl;
        cin >> input;
        
        cout << "\033[2J\033[1;1H";
        
        p.display();
        for(int i = 0; i < p.getDim() + 1; i++)
            cout << "* ";
        cout << "*\n";
        for(int i = 0; i < p.getDim(); i++) {
            cout << "*";
            for(int j = 0; j < p.getDim(); j++) {
                if(map[j][p.getDim() - i - 1]->getVisit())
                    cout << " +";
                else
                    cout << "  ";
            }
            cout << " *\n";
        }
        for(int i = 0; i < p.getDim() + 1; i++)
            cout << "* ";
        cout << "*\n";
        
        //Assesses the player status
        switch(toupper(input)) {
            case 'N':
                if(p.getY() == p.getDim() - 1)
                    cout << "You can't move north" << endl;
                else {
                    p.setY(p.getY() + 1);
                    map[p.getX()][p.getY()]->visit(p);
                }
                break;
            
            case 'S':
                if(p.getY() == 0)
                    cout << "You can't move south" << endl;
                else {
                    p.setY(p.getY() - 1);
                    map[p.getX()][p.getY()]->visit(p);
                }
                break;
            
            case 'E':
                if(p.getX() == p.getDim() - 1)
                    cout << "You can't move east" << endl;
                else {
                    p.setX(p.getX() + 1);
                    map[p.getX()][p.getY()]->visit(p);
                }
                break;
            
            case 'W':
                if(p.getX() == 0)
                    cout << "You can't move west" << endl;
                else {
                    p.setX(p.getX() - 1);
                    map[p.getX()][p.getY()]->visit(p);
                }
                break;
            
            default:
                cout << "Invalid input" << endl;
        }
        if(toupper(input) == 'Q' || p.getEnergy() < 1) {
            
            cout << "\033[2J\033[1;1H";
            
            p.display();
            for(int i = 0; i < p.getDim() + 1; i++)
                cout << "* ";
            cout << "*\n";
            for(int i = 0; i < p.getDim(); i++) {
                cout << "*";
                for(int j = 0; j < p.getDim(); j++) {
                    if(map[j][p.getDim() - i - 1]->getVisit())
                        cout << " +";
                    else
                        cout << "  ";
                }
                cout << " *\n";
            }
            for(int i = 0; i < p.getDim() + 1; i++)
                cout << "* ";
            cout << "*\n";
            
            cout << "Come back later, the treasure is waiting" << endl;
        }
        
        if(toupper(input) == 'Q' || p.getTreasure() || p.getEnergy() < 1)
            usleep(2000000);
        usleep(1000000);
        cout << "\033[2J\033[1;1H";
        
    } while(toupper(input) != 'Q' && !p.getTreasure() && p.getEnergy() > 0);
}