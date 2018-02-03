/*
 * card.h
 * Structure of card.h header file
 * author: Ashish Rajendra Kumar Sai
 */

#ifndef CARDGAME_CARD_H    //guard for header file
#define CARDGAME_CARD_H
#include <vector>          //for implimenting vector

enum cardSuit{
    //enumeration for suit
    Club = 1,Spade = 2,Heart = 3,Diamond = 4
};
enum cardValue{
    //enumberation for value
    Two,Three,Four,Five,Six,Seven,Eight,Nine,Ten,Jack,Queen,King,Ace
};

//Definition of class card //
class card {
private: //private variables
    cardSuit suit;
    cardValue value;
public: //public methods
    void printValue(); //output the value
    void giveValue();
    int editCardSuit(cardSuit suit0); //set the  Card Suit
    int editCardValue(cardValue value0); //set the  Card value
    cardSuit returnCardSuit(); // get the  Card Suit
    cardValue returnCardValue(); //get the  Card value
};

int getCardToStoreInStack(int setNum, vector<card> &C );  //declaration of non class method //

#endif //end of guard CARDGAME_CARD_H
