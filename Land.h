#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

class Land {
    public:
        virtual string description() = 0;
        virtual void visit(Player&) = 0;
        virtual bool getVisit() = 0;
        virtual void setVisit() = 0;
};

class Desert : public Land {
    private:
        bool visited;
    public:
        Desert() {visited = false;}
        string description() {return "an arid hot desert";}
        void visit(Player& p) {
            p.decEnergy();
            p.decEnergy();
            cout << "You traverse the hot desert and lose 2 energy points" << endl;
            visited = true;
        }
        bool getVisit() {return visited;}
        void setVisit() {visited = true;}
};

class Forest : public Land {
    private:
        bool visited;
    public:
        Forest() {visited = false;}
        string description() {return "a tropical dense forest";}
        void visit(Player& p) {
            p.decEnergy();
            cout << "You trek through the dense forest and lose 1 energy point" << endl;
            visited = true;
        }
        bool getVisit() {return visited;}
        void setVisit() {visited = true;}
};

class Orchard : public Land {
    private:
        bool visited;
    public:
        Orchard() {visited = false;}
        string description() {return "an orchard filled with apples";}
        void visit(Player& p) {
            p.incEnergy();
            p.incEnergy();
            cout << "You eat an apple in the orchard and gain 2 energy points" << endl;
            visited = true;
        }
        bool getVisit() {return visited;}
        void setVisit() {visited = true;}
};

class Lake : public Land {
    private:
        bool visited;
    public:
        Lake() {visited = false;}
        string description() {return "a lake with clear water";}
        void visit(Player& p) {
            p.incEnergy();
            cout << "You quench your thirst and gain 1 energy point" << endl;
            visited = true;
        }
        bool getVisit() {return visited;}
        void setVisit() {visited = true;}
};

class Ruins : public Land {
    private:
        bool visited;
    public:
        Ruins() {visited = false;}
        string description() {return "a glittering object in the distance";}
        void visit(Player& p) {
            p.setTreasure(true);
            cout << "CONGRATULATIONS!!!!\nYou explore the ruins and find the treasure!" << endl;
            visited = true;
        }
        bool getVisit() {return visited;}
        void setVisit() {visited = true;}
};