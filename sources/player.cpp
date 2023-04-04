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
    return this->score;
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
    if(this->stackSize == 0)
    {
        return Card();
    }

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

void Player :: addStats(int cardsTaken, string result)
{
    if(result == "win")
    {
        this->stats[0] = this->stats[0] + 1;
        this->score = this->score + cardsTaken;
    }
    else if(result == "lose")
    {
        this->stats[1] = this->stats[1] + 1;
    }
    else if(result == "draw")
    {
        this->stats[2] = this->stats[2] + 1;
        this->score = this->score + cardsTaken;
    }
};


void Player :: printStats()
{
    // wins, loses, draws amounts
    cout << this->name << " has " << this->stats[0] << " wins, " <<
    this->stats[1] << " loses and " << this->stats[2] << " draws." << endl;

    // total cards won
    cout << this->name << " has won " << this->score << " cards." << endl;

    // Win and draw percentages
    cout << this->name << " has " << (this->stats[0]) * 100 / 26 << "% win percentage and " <<
    (this->stats[2]) * 100 / 26 << "% draw percentage." << endl;
};