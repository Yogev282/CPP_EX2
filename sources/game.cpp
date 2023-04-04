#include "game.hpp"
#include <string.h>
#include <random>
#include <algorithm>

using namespace std;

Game :: Game(Player& p1, Player& p2) : player1(p1), player2(p2)
{

    this->deck = new Card[52];
    this->deckSize = 0;
    this->shuffleAndDeal();
    
};
// cant play after 26 turns
void Game :: playTurn() 
{
    

    if (&this->player1 == &this->player2){
        throw std::runtime_error ("Players can't be the same!");
        return;
    }
    
    if(this->player1.stacksize() == 0 || this->player2.stacksize() == 0){
        throw std::runtime_error ("One or both players have no cards left!");
        return;
    }

    if(this->turnOver == true)
    {
        this->lastTurn = "";
    }

    Card c1 = this->player1.playCard();
    Card c2 = this->player2.playCard();
    this->deckSize = this->deckSize + 2;
    this->turns++;

    int compare = c1.compareto(c2);
    if(compare == 1)
    {
        this->player1.addStats(this->deckSize, "win");
        this->player2.addStats(this->deckSize, "lose");

        this -> lastTurn =  this->lastTurn + this->player1.getName() + " played " + c1.print() + " " +
        this->player2.getName() + " played " + c2.print() + ". " + this->player1.getName() + " wins. ";

        this->turnOver = true;

        this->deckSize = 0;
        this->log = this->log + this->lastTurn + "\n\n";

    }
    else if(compare == -1)
    {
        this->player1.addStats(this->deckSize, "lose");
        this->player2.addStats(this->deckSize, "win");

        this -> lastTurn = this->lastTurn + this->player1.getName() + " played " + c1.print() + " " +
        this->player2.getName() + " played " + c2.print() + ". " + this->player2.getName() + " wins. ";

        this->turnOver = true;

        this->deckSize = 0;
        this->log = this->log + this->lastTurn + "\n\n";

    }
    else
    {
        // if both players have no cards left after the draw
         if(this->player1.stacksize() == 0 || this->player2.stacksize() == 0){
            this->player1.addStats((this->deckSize) / 2, "draw");
            this->player2.addStats((this->deckSize) / 2, "draw");
            return;
        }

        this->player1.playCard();
        this->player2.playCard();
        this->deckSize = this->deckSize + 2;
        this-> turns++;

        // if both players have no cards left after they played the second card
        if(this->player1.stacksize() == 0 || this->player2.stacksize() == 0){
            this->player1.addStats((this->deckSize) / 2 , "draw");
            this->player2.addStats((this->deckSize) / 2 , "draw");
            return;
        }

        // if both player still have cards left after the draw
        this->player1.addStats(0, "draw");
        this->player2.addStats(0, "draw");

        this -> lastTurn = this->lastTurn + this->player1.getName() + " played " + c1.print() + " " +
        this->player2.getName() + " played " + c2.print() + ". Draw. ";

        this->turnOver = false;
        this->playTurn();
        
    }
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
    if(this-> turns != 26)
    {
        cout << "the players played " << this->turns << endl;
        cout << "Game is not over yet!" << endl;
        return;
    }

    if(this->player1.cardesTaken() > this->player2.cardesTaken())
    {
        cout << this->player1.getName() <<  endl;
    }
    else if(this->player1.cardesTaken() < this->player2.cardesTaken())
    {
        cout << this->player2.getName() << endl;
    }
    else
    {
        throw std::runtime_error ("Draw!");
    }
};

void Game :: printLog()
{
    cout << this->log << endl;
};


void Game :: printStats()
{      
    this->player1.printStats();
    this->player2.printStats();
    
};


void Game::shuffleAndDeal() {
    std::string suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    for (int s = 0; s < 4; s++) {
        for (int i = 0; i < 13; i++) {
            this->deck[s*13+i] = Card(i+1, suits[s]);
        }
    }

    std::mt19937 rng(std::random_device{}()); // random seed generator by mt19937 algorithm
    std::shuffle(this->deck, this->deck + 52, rng); // shuffle deck by randomizing order (seed)


    for(int i = 0; i < 26; i++)
    {
        this->player1.addCardtoEnd(this->deck[i]);
    }

    for(int i = 26; i < 52; i++)
    {
        this->player2.addCardtoEnd(this->deck[i]);
    }
}
