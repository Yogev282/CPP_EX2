#ifndef GAME_HPP
#define GAME_HPP
#include <string>
#include <iostream>
#include "player.hpp"
#include "card.hpp"

using namespace std;
using namespace ariel;

    class Game{

        public:
        Game(Player player1, Player player2);
        void playTurn();
        string printLastTurn();
        void playAll();
        string printWiner();
        void printLog();
        void printStats();

    };


#endif