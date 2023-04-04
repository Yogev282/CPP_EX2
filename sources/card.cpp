#include "card.hpp"

using namespace ariel;

Card :: Card(int value, string suit){
    
    this->value = value;
    this->suit = suit;

};

Card :: Card(){
    
    this->value = 0;
    this->suit = "";
};

int Card :: compareto(Card other){
    // Ace wins everything except 2
    if(this->value == 1 && (other.value != 1 && other.value != 2)){
        return 1;
    }
    if((this->value != 1 && other.value != 2) && other.value == 1){
        return -1;
    }
    

    if(this->value > other.value){
        return 1;
    }
    else if(this->value < other.value){
        return -1;
    }
    else{
        return 0;
    }
};

string Card :: print(){
    string tmp = "";
    if(this->value == 1)
    {
        tmp = tmp + "Ace of " + this->suit;
        return tmp;
    }
    if(this->value == 11)
    {
        tmp = tmp + "Jack of " + this->suit;
        return tmp;
    }
    if(this->value == 12)
    {
        tmp = tmp + "Queen of " + this->suit;
        return tmp;
    }
    if(this->value == 13)
    {
        tmp = tmp + "King of " + this->suit;
        return tmp;
    }
    tmp = tmp + to_string(this->value) + " of " + this->suit;
    return tmp;
};

