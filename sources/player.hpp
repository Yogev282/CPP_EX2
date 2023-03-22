#ifndef PLAYER_HPP
#define PLAYER_HPP

    #include <string>
    #include <iostream>
    #include "card.hpp"

    using namespace std;
    using namespace ariel;

    class Player{
        string name;
        

        public:
        Player(string name);
        int stacksize();
        int cardesTaken();
        void addCardtoEnd(Card card);
        void addCardtoStart(Card card);
        Card playCard();
        
    };



#endif