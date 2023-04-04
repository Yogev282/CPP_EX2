#ifndef PLAYER_HPP
#define PLAYER_HPP

    #include <string>
    #include <iostream>
    #include "card.hpp"
    #include <array>

    using namespace std;
    using namespace ariel;

    class Player{
        string name;
        Card* cards;
        int stackSize;
        std::array<int, 3> stats{0, 0, 0}; // 0 - wins, 1 - loses, 2 - draws
        
        int score = 0;

        public:
        Player(string name);
        Player();
        int stacksize();
        int cardesTaken();
        void addCardtoEnd(Card card);
        void addCardtoStart(Card card);
        Card playCard();
        string getName();
        void addStats(int cardsTaken, string result);
        void printStats();
    };



#endif