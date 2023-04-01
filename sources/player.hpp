#ifndef PLAYER_HPP
#define PLAYER_HPP

    #include <string>
    #include <iostream>
    #include "card.hpp"

    using namespace std;
    using namespace ariel;

    class Player{
        string name;
        Card* cards;
        int stackSize;
        int stats[3] = {0,0,0}; // 0 - wins, 1 - loses, 2 - draws

        public:
        Player(string name);
        Player();
        int stacksize();
        int cardesTaken();
        void addCardtoEnd(Card card);
        void addCardtoStart(Card card);
        Card playCard();
        string getName();
        
    };



#endif