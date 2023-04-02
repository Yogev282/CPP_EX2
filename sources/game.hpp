#ifndef GAME_HPP
#define GAME_HPP
#include <string>
#include <iostream>
#include "player.hpp"
#include "card.hpp"

using namespace std;
using namespace ariel;

    class Game{

        Player& player1;
        Player& player2;
        Card *deck;
        int deckSize;
        string lastTurn;
        string log;
        bool turnOver = true;

        public:
        Game(Player& player1, Player& player2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
        void shuffleAndDeal();
    };


#endif