#ifndef CARD_HPP
#define CARD_HPP
#include <string>
#include <iostream>

using namespace std;


namespace ariel{

    class Card{
        public:
        Card(int value, string suit);
        Card();
        int compareto(Card other);
    };

}

#endif