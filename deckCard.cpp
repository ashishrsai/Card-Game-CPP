/*
 * deckCard.cpp
 * Execution of deckCard object and its services
 * author: Ashish Rajendra Kumar Sai
 */

using namespace std;
#include <iostream>
#include <algorithm>    // to implement random shuffle algorithm
#include <vector>       //to implement vectors

struct insufficientSet : public exception{
    // Exception to handle illegal entry of number of sets
    const char * badSet() const throw () {
        return "Please enter a valid number of set, the game can not be played with provided number of set.";
    }

    // Exception to handle illegal entry of number of users
    const char * badUser() const throw () {
        return "Please enter a valid number of users, the game can not be played with provided number of Users.";
    }

};

#include "card.h"  //Import custom header file card.h//
#include "deckProt.h" //Import custom header file deckProts.h//
#include "deckCard.h" //Import custom header file deckcard.h//

/*
 * createEmptyCardDeck(int deckNo)
 * Creates an empty deck of cards, ie.deck of cards with no cards
 *
 * parameter:int deckNo
 * return: bool //this will signify the outcome of execution of function 
 */

bool deckCard::createEmptyCardDeck(int deckNo){
    // definition of creating an empty card deck
    deck[deckNo].emptyTheCardDeck();
    return true;
}

/*
 * createInitialisedCardDeck(int setNum, int numberOfDeck)
 * Creates  a  deck of  cards  initialised  with  the  specified number of sets of cards. Sets of cards are stored in an ordered fashion
 *
 * parameter:int setNum //Number of sets
 *	     int numberOfDeck //Number of decks
 * return: int i //number of deck
 */

int deckCard::createInitialisedCardDeck(int setNum, int numberOfDeck){
    //definition of initializing the card deck with defined parameters //
    deck.resize(52);
    int i = 1;
    try{
        //handle insufficient set exception //
        cout<<setNum;
        if (setNum < 1 ){
            throw insufficientSet();
        }
        deck[i].modifySetNum(setNum);
        getCardToStoreInStack(deck[i].setNum,deck[i].Cards);
        i++;

    } catch (insufficientSet& b){
        cout<< "BADSET caught" <<endl;
        cout<<b.badSet()<<endl;
        exit(1);
    }
    return i;
}

/*
 * deleteCardDeck(int location)
 * Deletes a deck of cards.
 *
 * parameter:int location
 * return: bool //this will signify the outcome of execution of function 
 */

bool deckCard::deleteCardDeck(int location){
    //delete the card deck here based on location //
    deck.erase(deck.begin() + location);
    cout<<"The size of deck after clearing it is = "<<deck[location].Cards.size()<<endl; //Output size of deck after action //
    return 0;
}
/*
 * printDeckSize()
 * Will print out size of deck
 *
 * return: bool //this will signify the outcome of execution of function 
 */

bool deckCard::printDeckSize(){
    //output size of deck
    cout<<"I am another size but of deck[1] this time"<<deck[1].Cards.size();
}

/*
 * initialiseCardDeck(int setNum, int deckNo)
 * function used initialise card deck
 *
 * return: bool //this will signify the outcome of execution of function 
 */

bool initialiseCardDeck(int setNum, int deckNo){

    //createInitialisedCardDeck();
}

/*
 * getNumberOfCards(int deckNo){
 * function used to get number of cards in a deck
 *
 * parameter: int deckNo // the number of deck for which number of cards is to be obatained
 * return: int numberOfCards
 */

int  deckCard::getNumberOfCards(int deckNo){
    //obtain number of cards in a deck //
    int numberOfCards = deck[deckNo].Cards.size();
    return numberOfCards;
}

/*
 * getTopCard(int deckNo)
 * function returns the top card of deck with deckNo
 *
 * parameter: int deckNo // Used in order to determine the deck of which top card is to be returned
 * return: bool //this will signify the outcome of execution of function   
 */

bool deckCard::getTopCard(int deckNo){
    // obtain top/front card as a card object
    card topCard;
    topCard = deck[deckNo].Cards.front();
    return 0;
}

/*
 * getACard(int number, int deckNo)
 * function used to get the card from the list of cards as a card object
 * this function will delete the card after getting it
 *
 * parameter: int number //Number of card which is to obtain 
 *	      int deckNo //deckNo of which we have to obtain card
 * return: card returnCard //card is returned
 */

card deckCard::getACard(int number, int deckNo){
    // gets the card from the list of cards as a card object
    card returnCard;
    returnCard = deck[deckNo].Cards.at(number);
    deck[deckNo].Cards.erase(deck[deckNo].Cards.begin()+number);
    return returnCard;
}

/*
 * lookAtCard(int number,int deckNo)
 * function used look at the card at location number in deck deckNo
 *
 * parameter: int number //Number of card which is to obtain 
 *	      int deckNo //deckNo of which we have to obtain card
 * return: bool //this will signify the outcome of execution of function 
 */

bool deckCard::lookAtCard(int number,int deckNo){
    //compare and show location of a card after comparison //
    cout<<"++++++++++++++++++++++++++++++++++++++ ENTERING LOOK AT A CARD ++++++++++++++++++++++++"<<endl;
    cout<<"The card at location "<<number<<" is "<<endl;
    deck[deckNo].Cards.at(number).printValue();
    return 0;
}

/*
 * moveAllCards(int sourceDeck,int destinationDeck)
 * function used to move all cards from sourceDeck to destinationDeck
 *
 * parameter: int sourceDeck //deck number for source 
 *	      int destinationDeck //deck number for destination

 * return: int getNumberOfCards(destinationDeck) //returns number of cards at destination deck
 */

int  deckCard::moveAllCards(int sourceDeck,int destinationDeck){
    // move all the cards from one deck to another.
    cout<<"++++++++++++++++++++++++++++++++++++++ ENTERING MOVE ALL CARDS ++++++++++++++++++++++++"<<endl;
    std::move(deck[sourceDeck].Cards.begin(),deck[sourceDeck].Cards.end(),back_inserter(deck[destinationDeck].Cards));
    deck[sourceDeck].Cards.clear();
    getNumberOfCards(sourceDeck);
    cout<<"Number of cards in destination deck"<<endl;
    return getNumberOfCards(destinationDeck);
}

/*
 * addCard(card &Card,int deckNo)
 * function used to a card in deck with deckNo
 *
 * parameter: card &Card //reference to card
 *	      int deckNo //Number of deck in which we have to add card
 * bool //this will signify the outcome of execution of function  
 */

bool deckCard::addCard(card &Card,int deckNo){
    //adds a card to the deck of cards
    getNumberOfCards(deckNo);
    deck[deckNo].Cards.insert(deck[deckNo].Cards.begin(),Card);
    return 0;
}

/*
 * shuffleDeck(int deckNo)
 * function used to shuffle cards in deck deckNo
 *
 * parameter: int deckNo //Number of deck
 * bool //this will signify the outcome of execution of function
 */

bool deckCard::shuffleDeck(int deckNo){
    //Shuffle the deck of cards specified by deckno//
    getTopCard(deckNo);
    random_shuffle(deck[deckNo].Cards.begin(),deck[deckNo].Cards.end());
    getTopCard(deckNo);

}

