#include "game.hpp"
#include <string.h>

using namespace std;

Game :: Game(Player p1, Player p2)
{
    this->player1 = p1;
    this->player2 = p2;
    this->deck = new Card[52];
    this->deckSize = 0;
    this->shuffleAndDeal();
    
};

void Game :: playTurn()
{
    if(this->player1.stacksize() == 0 || this->player2.stacksize() == 0){
        return;
    }

    this->lastTurn = "";

    Card c1 = this->player1.playCard();
    Card c2 = this->player2.playCard();
    this->deckSize = this->deckSize + 2;
    
    int compare = c1.compareto(c2);
    if(compare == 1)
    {
        this->player1.addCardtoEnd(c1);
        this->player1.addCardtoEnd(c2);
        for(int i = 0; i < this->deckSize; i++)
        {
            this->player1.addCardtoEnd(this->deck[i]);
        }
        this->deckSize = 0;

        this -> lastTurn =  this->player1.getName() + " played " + c1.print() + " " +
        this->player2.getName() + " played " + c2.print() + ". " + this->player1.getName() + " wins. " + this->lastTurn;

    }
    else if(compare == -1)
    {
        this->player2.addCardtoEnd(c1);
        this->player2.addCardtoEnd(c2);
        for(int i = 0; i < this->deckSize; i++)
        {
            this->player2.addCardtoEnd(this->deck[i]);
        }
        this->deckSize = 0;
        this -> lastTurn =  this->player1.getName() + " played " + c1.print() + " " +
        this->player2.getName() + " played " + c2.print() + ". " + this->player2.getName() + " wins. " + this->lastTurn;
    }
    else
    {
        this->deck[this->deckSize] = c1;
        this->deckSize++;
        this->deck[this->deckSize+1] = c2;
        this->deckSize++;

        this -> lastTurn =  this->player1.getName() + " played " + c1.print() + " " +
        this->player2.getName() + " played " + c2.print() + ". Draw. " + this->lastTurn;

        this->playTurn();
        
    }

    this->log = this->log + this->lastTurn + "\n\n";
    
};

void Game :: printLastTurn()
{
    cout << this->lastTurn << endl << endl;
};

void Game :: playAll()
{
    while(this->player1.stacksize() != 0 && this->player2.stacksize() != 0)
    {
        this->playTurn();
    }
};

void Game :: printWiner()
{
    if(this->player1.stacksize() == 0)
    {
       cout << this->player2.getName() << endl;
    }
    else
    {
        cout << this->player1.getName() << endl;
    }
};

void Game :: printLog()
{
    cout << this->log << endl;
};
/// @brief gdfgdfgdf////////////////////////////////////////////////////////////////////////////////
void Game :: printStats()
{
    
};
/// @brief gdfgdfgdf ///////////////////////////////////////////////////////////////////////////////

void Game::shuffleAndDeal() {
    std::string suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    for (int s = 0; s < 4; s++) {
        for (int i = 0; i < 13; i++) {
            this->deck[s*13+i] = Card(i+1, suits[s]);
        }
    }

    for(int i = 0; i < 52; i++)
    {
        int j = rand() % 52;
        Card tmp = this->deck[i];
        this->deck[i] = this->deck[j];
        this->deck[j] = tmp;
    }

    for(int i = 0; i < 26; i++)
    {
        this->player1.addCardtoEnd(this->deck[i]);
    }

    for(int i = 26; i < 52; i++)
    {
        this->player2.addCardtoEnd(this->deck[i]);
    }
}
