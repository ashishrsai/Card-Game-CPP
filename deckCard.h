/*
 * main.cpp
 * Structure of deckCard.h header file
 * author: Ashish Rajendra Kumar Sai
 */

#ifndef CARDGAME_DECKCARD_H  //guard for header file
#define CARDGAME_DECKCARD_H

#include <vector>
class deckCard {
//class definition

public:
    // public members
    vector <deckProt> deck; // vector type deckprot object deck
    int createInitialisedCardDeck(int setNum, int deckNumber);
    bool deleteCardDeck(int location); //flag for deletion of carddeck
    bool printDeckSize(); //  show deck size
    int getNumberOfCards(int deckNo);  // variable to get no. of cards in a deck
    bool getTopCard(int deckNo); // get the card on top of the deck
    bool lookAtCard(int number,int deckNo); // view card in certain deck
    card getACard(int number, int deckNo); // returns card object for the selection
    int  moveAllCards(int sourceDeck,int destinationDeck); // move all the cards from one deco to another
    bool addCard(card &Card,int deckNo);  // add a new card
    bool shuffleDeck(int deckNo);  // reshuffle deck
    bool createEmptyCardDeck(int deckNo); // create empty card deck

};


#endif //// end of guard  CARDGAME_DECKCARD_H
