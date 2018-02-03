/*
 * deckProt.cpp
 * Execution of deckProt and its services
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

#include "card.h"  //Import custom header file card.h//
#include "deckProt.h" //Import custom header file deckProts.h//

/*
 * returnSetNum()
 * Method used to get the value of setNum
 *
 * return: setNum // returns setNum 
 */

int deckProt::returnSetNum() {
    return setNum;
}

/*
 * returnCard() 
 * Method called to get a card from deckProt
 * 
 * return: vector <card> Cards //returns a card
 */

vector <card> deckProt::returnCard() {
    //return Vector Cards
    return Cards;
}
/*
 * modifySetNum(int valueToSet)
 * Method used to modify the the value of setNum
 *
 * parameter:int valueToSet //value which is to be saved 
 * 
 * return: int // this will signify the outcome of execution of function 
 */

int deckProt::modifySetNum(int valueToSet){
    //set value of setNum
    setNum = valueToSet;
    return 0;
}
