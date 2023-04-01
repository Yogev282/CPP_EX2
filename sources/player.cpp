#include "player.hpp"
#include "card.hpp"

using namespace std;
using namespace ariel;

Player :: Player(string name)
{
    this->name = name;
    this->cards = new Card[52];
    this->stackSize = 0;
};

Player :: Player()
{
    this->name = "";
    this->cards = new Card[52];
    this->stackSize = 0;
};

int Player :: stacksize()
{
    return this->stackSize;
};

int Player :: cardesTaken()
{
    int tmp = this->stackSize - 26;
    if (tmp < 0)
    {
        return 0;
    }
    return tmp;
};

void Player :: addCardtoEnd(Card c)
{
    this->cards[this->stackSize] = c;
    this->stackSize++;
};

void Player :: addCardtoStart(Card c)
{
    for(int i = this->stackSize; i > 0 ; i--)
    {
        this->cards[i] = this->cards[i-1];
    }
    this->cards[0] = c;
    this->stackSize++;
};

Card Player :: playCard()
{
    Card tmp = this->cards[0];
    for(int i = 0; i < this->stackSize; i++)
    {
        this->cards[i] = this->cards[i+1];
    }
    this->stackSize--;
    return tmp;
};

// getters

string Player :: getName()
{
    return this->name;
};