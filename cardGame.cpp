/*
 * cardGame.cpp
 * Execution of card game services
 * author: Ashish Rajendra Kumar Sai
 */

using namespace std;
#include <iostream>
#include <algorithm>    // to implement random shuffle algorithm
#include <vector>       //to implement vectors


//custom exception handler which derives exception class
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

#include "card.h"          //Import custom header file card.h//
#include "deckProt.h"      //Import custom header file deckProt.h for deck //
#include "deckCard.h"      //Import custom header file deckCard.h//
#include "cardGame.h"      //Import custom header file cardGame.h//

/*
 * returnNumUser()
 * function used to access Number of Users
 * returnNumUser is a public member of class cardGame
 *
 * parameter:
 * the function is invoked by an object of class card game
 * return: int numUser (The value stored in the variable)
 */
int cardGame::returnNumUser() {
    return numUser;
}

/*
 * returnSetNum()
 * function used to access Number of sets
 * returnNumSet is a public member of class cardGame
 *
 * parameter:
 * the function is invoked by an object of class card game
 * return: int numSet (The value stored in the variable)
 */

int cardGame::returnSetNum() {
    return setNum;
}

/*
 * putValueInNumUserAndSetNum(numUser0,setNum0)
 * Assign values to object variables for no.of players  
 * and decks using this method
 *
 * parameter:int numUser0 // Used in order to save values in the variable numUser 
 *	     int setNum0 // Used in order to save values in the variable setNum
 * 
 * return: int // 0 would signify SUCESSS_EXIT
 */
int cardGame::putValueInNumUserAndSetNum(int numUser0,int setNum0) {
    // Assign values to object variables for no.of players and decks using this method //
    numUser = numUser0;
    setNum = setNum0;
    return 0;
}


/*
 * getValuesFromUser(int numUser0,int setNum0)
 * Assign values to object variables for no.of players  
 * and decks using this method
 *
 * parameter:int numUser0 // Used in order to save values in the variable numUser 
 *	     int setNum0 // Used in order to save values in the variable setNum
 * 
 * return: int // 0 would signify SUCESSS_EXIT
 */

int cardGame::getValuesFromUser(int numUser0,int setNum0){
    //Method to take game related values from the end user of game.
    int variable1,variable2; // temporary variables to set no. of players and number of decks used in the game
    cout<<"============================================================================="<<endl;
    cout<<"Please enter the number of players playing this game "<<endl;
    cin>>variable1;

    cout<<"============================================================================="<<endl;
    cout<<"Well Done! Please enter the number of set of card that you wish to use"<<endl;
    cin>>variable2;

    cardGame::putValueInNumUserAndSetNum(variable1,variable2); // call method to set values to the class object of cardGame//
    return 0;
}

/*
 * createDeckForPlayers(int numberOfDeck, int numUser)
 * Method used to create object deck using deckCard  
 * this method will invoke method in class deckCard using deckcard object
 *
 * parameter:int numUser0 // Used in order to save values in the variable numUser 
 *	     int setNum0 // Used in order to save values in the variable setNum
 * 
 * return: int // 0 would signify SUCESSS_EXIT
 */

int cardGame::createDeckForPlayers(int numberOfDeck, int numUser){
    //Method  to create 'decks' to play the game based on user inputs
    int numberOfPlayer = numUser;
    int incrementedNumberOfDeck = numberOfDeck+1;

    try{
    //Exception Handler for illegal number of decks
        if(numberOfPlayer < 1){
            throw insufficientSet();
        }

    }catch (insufficientSet& u){
        //Exception Handler for illegal number of user
        cout<< "BADUSER caught" <<endl;
        cout<<u.badUser()<<endl;
        exit(1);
    }

    for (int i = 1; i <=numberOfPlayer ; ++i) {
        //create card decks based on number of players
        deckcard.deckCard::createEmptyCardDeck(incrementedNumberOfDeck);
        incrementedNumberOfDeck++;
    }

    return incrementedNumberOfDeck-1;
}


/*
 * distributeCards(int numberOfDeckAfterAllPlayers)
 * Method to distribute cards to all the players where each gets 7 cards one after another 
 *
 * parameter:int numberOfDeckAfterAllPlayers // Used in order to pass number of users so that cards can be distributed
 * 
 * return: bool // this will signify the outcome of execution of function 
 */
bool cardGame::distributeCards(int numberOfDeckAfterAllPlayers){
    //Method to distribute cards to all the players where each gets 7 cards one after another
    //deck[0] is reserved for played cards
    //deck[1] is reserved for shuffled deck
    //starting from 1 till numberOfDeckAfterAllPlayers are the decks for users
    try {
       // try block to handle distribution of the cards in the deck to players.//
        card tempCard;  // create object for class card //

        for (int i = 0; i < 7; ++i) {
            for (int j = 2; j <= numberOfDeckAfterAllPlayers; ++j) {
                tempCard = deckcard.deckCard::getACard(0, 1); // use  tempCard to store the cards for distribution//
                deckcard.deckCard::addCard(tempCard, j);
                if (deckcard.deck[1].Cards.size() == 0){
                    throw insufficientSet();
                }

            }
        }
    } catch (insufficientSet& b){
        //Catch exception if there are not enough cards//
        cout<< "BADSET caught" <<endl;
        cout<<b.badSet()<<endl;
        exit(1);
    }
}

/*
 * addCardToPlayedDeck()
 * Method used add card to played deck  
 * this method will invoke method in class deckCard using deckcard object
 * 
 * return: bool // this will signify the outcome of execution of function 
 */

bool cardGame::addCardToPlayedDeck(){
    //add current card to played deck
    deckcard.deckCard::addCard(deckcard.deck[1].Cards.front(),0);
    deckcard.deck[1].Cards.erase(deckcard.deck[1].Cards.begin()+0);

}

/*
 * getTheCardsInHand(int i)
 * Method to get list all cards in deck of user i
 *
 * parameter:int i // Used in order to pass number of user so that cards can be obtained
 * 
 * return: bool // this will signify the outcome of execution of function 
 */

bool cardGame::getTheCardsInHand(int i){
    // to get the cards in hand
    int size = deckcard.deck[i].Cards.size();
    for (int j = 0; j <size ; ++j) {
        cout<<"||";
        deckcard.deck[i].Cards.at(j).printValue();
        cout<<"||";
    }
}

/*
 * gamePlay(int numberOfDeckAfterAllPlayers)
 * Method to initiate the game with number of decks after distribution of cards
 *
 * parameter:int numberOfDeckAfterAllPlayers //this is number of decks that have been created after distribution of cards to all users
 * 
 * return: bool // this will signify the outcome of execution of function 
 */

bool cardGame::gamePlay(int numberOfDeckAfterAllPlayers){
    //Function to initiate the game using numberOfDeckAfterAllPlayers for initiation//
    card cardToBePlayed; //card object which stores the card to be played by player//
    card cardToBeComparedWith; //card object which stores the card to be compared to by player//
    card cardWhichIsCompared; //card object which stores the in hand card which by player//
    card cardToBeTakenFromShuffledDeck; //card object which stores the card picked up by the player from shuffled deck//

    cout<<"============================================================================="<<endl;
    cout<<"============================GAME STARTS NOW=================================="<<endl;
    int countMe = 0;  //Variable to ensure multiple itrations//
    int gameEnd = 0;  // Variable to track end of game //
    int iAmAStupidCounter =0; //counter variable to track no. of shuffles that have been done //
    do{
        // keep running till one player runs out of cards//
        for (int i = 2; i <=numberOfDeckAfterAllPlayers ; ++i) {

            cardToBeComparedWith = deckcard.deck[0].Cards.front(); // assign top of deckcard  to cardToBeComparedWith
            for (int j = 0; j <deckcard.deck[i].Cards.size() ; ++j) {

                cardWhichIsCompared = deckcard.deck[i].Cards.at(j); //// assign cardWhichIsCompared with card in player deck
                if(deckcard.deck[1].Cards.size()==0){
                    //Reshuffle card deck here //
                    deckcard.deckCard::moveAllCards(0,1);
                    addCardToPlayedDeck();
                    iAmAStupidCounter++;
                }

                if(cardWhichIsCompared.card::returnCardSuit() == cardToBeComparedWith.card::returnCardSuit() ){
                    // Make the move to play the card  and show details of the move //
                    cardToBePlayed = deckcard.deckCard::getACard(j,i);
                    cout<<"USER NO "<<i-1<<" IS PLAYING - ";
                    cardToBePlayed.printValue();
                    cout<<endl;
                    deckcard.deckCard::addCard(cardToBePlayed,0);
                    break;
                }
                else{
                    if (cardWhichIsCompared.card::returnCardValue() == cardToBeComparedWith.card::returnCardValue()){
                        // Play move if the card matches //
                        cardToBePlayed = deckcard.deckCard::getACard(j,i);
                        cout<<"USER NO "<<i-1<<" IS PLAYING - ";
                        cardToBePlayed.printValue(); // show the value of the card
                        cout<<endl;
                        deckcard.deckCard::addCard(cardToBePlayed,0);  // add the card
                        break;
                    }
                    else{
                        // Switch the card which is being compared //
                        if(j == (deckcard.deck[i].Cards.size())-1 ){
                            if(deckcard.deck[1].Cards.size()==0){
                                //shuffle the card deck if its empty
                                deckcard.deckCard::moveAllCards(0,1);
                                addCardToPlayedDeck();
                                iAmAStupidCounter++;
                            }
                            cout<<"THE USER NO "<<i-1<<" IS TAKING A CARD OUT FROM SHUFFLED DECK";
                            cardToBeTakenFromShuffledDeck = deckcard.deckCard::getACard(0,1);  // Play move for the card //
                            deckcard.deckCard::addCard(cardToBeTakenFromShuffledDeck,i);
                            cout<<" AND HAS THE FOLLOWING CARDS IN HAND NOW : "<<endl;
                            getTheCardsInHand(i); // show the number of cards in hand //
                            cout<<endl;
                            break;
                        }

                    }
                }
            }

            if(deckcard.deck[i].Cards.size()==0){
                // Game over if a player run out of cards //
                cout<<"==========================GAME HAS ENDED NOW============================="<<endl;
                cout<<"THE USER NUMBER "<<i-1<<" HAS WON THE MATCH"<<endl;
                cout<<"========================================================================="<<endl;
                gameEnd = 1;
                break;
            }
        }
        countMe++;
    }while (gameEnd != 1); // keep running till someone wins the game
    cout<<"This is how many times we had to move all cards from Played to Shuffled "<<iAmAStupidCounter<<endl; //no of times deck has been shuffled//
}

/*
 * startGame()
 * Method to start the game
 * invoked by playGame with an object of class cardGame
 * return: bool // this will signify the outcome of execution of function 
 */

bool cardGame::startGame(){
    // initiate the game here //
    getValuesFromUser(numUser,setNum); // get values of players and decks //
    numUser = returnNumUser(); //set value
    setNum = returnSetNum(); //set value
    int numberOfDeck = 0;
    int numberOfShuffledDeck; //number of shuffled decks in the game
    int numberOfDeckAfterAllPlayers; // deck count after distribution
    numberOfDeck = deckcard.deckCard::createInitialisedCardDeck(setNum,1) - 1;

    deckcard.deckCard::shuffleDeck(numberOfDeck); //declare shuffleDeck

    numberOfShuffledDeck = numberOfDeck;
    numberOfDeckAfterAllPlayers = createDeckForPlayers(numberOfDeck,numUser);
    distributeCards(numberOfDeckAfterAllPlayers);

    //we use this function to store a card in playedDeck
    addCardToPlayedDeck();

    //The code below displays information related to the decks created and size of each deck.
    cout<<"============================================================================="<<endl;
    cout<<"==============================DECK INFORMATION==============================="<<endl;
    for (int i = 2; i <=numberOfDeckAfterAllPlayers ; ++i) {

        cout<<"The size of deck for"<<i-1<<" th user after distribution is "<<deckcard.deck[i].Cards.size()<<endl;
    }

    cout<<"The size of deck for shuffled deck after distribution is "<<deckcard.deck[1].Cards.size()<<endl;
    cout<<"The size of deck for played deck after distribution is "<<deckcard.deck[0].Cards.size()<<endl;

    cout<<"============================================================================="<<endl;
    cout<<"============================================================================="<<endl;
    cout<<"=================================TOP CARD===================================="<<endl;
    cout<<"The card on Top is ";
    deckcard.deck[0].Cards.front().printValue();
    cout<<" ."<<endl;
    cout<<"============================================================================="<<endl;

    //now we write the logic for actual game in the function given below
    gamePlay(numberOfDeckAfterAllPlayers); // initiate the gameplay
    cout<<"-----------FINAL OUTPUT------------"<<endl;
    cout<<"The size of deck for shuffled deck after distribution is "<<deckcard.deck[1].Cards.size()<<endl;
    cout<<"The size of deck for played deck after distribution is "<<deckcard.deck[0].Cards.size()<<endl;
    for (int i = 2; i <=numberOfDeckAfterAllPlayers ; ++i){
        cout<<"The size of player "<<i-1<<" deck "<<deckcard.deck[i].Cards.size()<<endl;
    }
}

/*
 * playGame(cardGame game)
 * Method called by main which will start the game
 *
 * parameter:cardGame game //object game of class cardGame is passed as parameter
 * 
 * return: bool // this will signify the outcome of execution of function 
 */

bool playGame(cardGame game){
    // start playing the game//
   game.startGame();
}

