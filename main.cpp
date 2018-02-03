/*
 * main.cpp
 * The main program to accomplish the game
 * author: Ashish Rajendra Kumar Sai
 */

using namespace std;
#include <iostream>
#include <algorithm>   // to implement random shuffle algorithm
#include <vector>      //to implement vector 

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


int main() {

    cardGame game;  //Create game as cardGame object
    playGame(game); //Initialize the playGame() method with the cardGame object as parameter
    return 0;
}
