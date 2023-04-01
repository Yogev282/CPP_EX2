#ifndef CARD_HPP
#define CARD_HPP
#include <string>
#include <iostream>

using namespace std;


namespace ariel{

    class Card{
        
        int value;
        string suit;

        public:

        Card(int value, string suit);
        Card();
        int compareto(Card other);
        string getSuit();
        int getValue();
        string print();
    };

}

#endif