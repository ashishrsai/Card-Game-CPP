/*
 * cardGame.h
 * Structure of cardGame.h header file
 * author: Ashish Rajendra Kumar Sai
 */


#ifndef CARDGAME_CARDGAME_H  //guard for header file
#define CARDGAME_CARDGAME_H


class cardGame{
//class definition

public:
    // public members
    deckCard deckcard; //deckcard object
    int getValuesFromUser(int numUser0,int setNum0);  //get game values from user
    int returnNumUser(); //return values of num from user?
    int returnSetNum(); // return the value assigned ?
    int putValueInNumUserAndSetNum(int numUser0,int setNum0); //set game values to variables
    int createDeckForPlayers(int numberOfDeck,int numUser); // create the decks
    bool distributeCards(int numberOfDeckAfterAllPlayers);  //flag for distribution of cards
    bool addCardToPlayedDeck(); // adding player to deck
    bool gamePlay(int numberOfDeckAfterAllPlayers); // initiating  gameplay
    bool getTheCardsInHand(int i); // getting cards in hand to play game
    bool startGame();  //for successful initiation of game

private:
    //private  members players and no. of decks
    int numUser;
    int setNum;

};
bool playGame(cardGame game); // non class function declaration


#endif // end of guard CARDGAME_CARDGAME_H
