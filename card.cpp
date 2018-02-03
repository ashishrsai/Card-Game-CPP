/*
 * card.cpp
 * Execution of card object and its services
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

#include "card.h"   //import card.h and define its methods below//

/*
 * editCardSuit(cardSuit suit0)
 * function used to modify value of suit
 *
 * parameter:cardSuit suit0  //value to be stored in suit
 * return: int // this will signify the outcome of execution of function 
 */

int card::editCardSuit(cardSuit suit0) {
    //Set the suit of cardSuit to the one selected
    suit = suit0;
    return 0;
}

/*
 * editCardValue(cardValue value0)
 * function used to modify value of value
 *
 * parameter:cardSuit value0  //value to be stored in value
 * return: int // this will signify the outcome of execution of function 
 */


int card::editCardValue(cardValue value0) {
    //Set the value of cardValue to the one selected
    value = value0;
    return 0;
}

/*
 * returnCardSuit()
 * function used to access suit of card
 *
 * return: cardSuit suit //value of suit is returned
 */

cardSuit card::returnCardSuit() {
    // returns the suit of the card selected
    return suit;
}

/*
 * returnCardSuit()
 * function used to access suit of value
 *
 * return: cardSuit value //value of value is returned
 */

cardValue card::returnCardValue() {
    // returns the value of the card selected
    return value;
}

/*
 * giveValue()
 * function used to print out the value of card
 * return: void
 */

void card::giveValue(){
    //To obtain the 'value' of the card that has been selected using a switch //
    switch (value){
        case 0 : {
            cout<<"- Two";
            break;
        }
        case 1 :{
            cout<<"- Three";
            break;
        }
        case 2 :{
            cout<<"- Four";
            break;
        }
        case 3 :{
            cout<<"- Five";
            break;
        }
        case 4 :{
            cout<<"- Six";
            break;
        }
        case 5 :{
            cout<<"- Seven";
            break;
        }
        case 6 :{
            cout<<"- Eight";
            break;
        }
        case 7:{
            cout<<"- Nine";
            break;
        }
        case 8:{
            cout<<"- Ten";
            break;
        }
        case 9:{
            cout<<"- Jack";
            break;
        }
        case 10:{
            cout<<"- Queen";
            break;
        }
        case 11:{
            cout<<"- King";
            break;
        }
        case 12:{
            cout<<"- Ace";
            break;
        }
    }
}

/*
 * printValue()
 * function used to print out the suit and value of card
 * return: void
 */

void card::printValue(){
    //To obtain the suit of the card selected using a switch  and invoke call to obtain its value//
    switch (suit){
        case 1:{
            cout<<"Club ";
            giveValue();
            break;
        }
        case 2:{
            cout<<"Spade ";
            giveValue();
            break;
        }
        case 3:{
            cout<<"Heart ";
            giveValue();
            break;
        }
        case 4:{
            cout<<"Diamond ";
            giveValue();
            break;
        }
    }
}


int giveItToStack(int i, int count, vector <card> &C);  // giveItToStack declaration

/*
 * getCardToStoreInStack(int setNum, vector<card> &C )
 * function used to store card to deck
 * parameter: int setNum //number of set
 *	      vector<card> &C //refernce to the card
 * return: int // this will signify the outcome of execution of function 
 */

int getCardToStoreInStack(int setNum, vector<card> &C ){
    //function to use the card according to the specifics of the user 'setNum' and store it for card Stack//
    C.resize(52*setNum);  //resize C to number entered by user//

    int l = 0;  //loop counter variables
    int k = 52;
    int count = 0;
    int z = 0;

    for (int j = 0; j <setNum ; ++j) {

        if(count > 0){
            z = count * 52;
            l = (count * 52)+1 ;
            k = l+52;
        }
        int countClub = 0;  //variable to count number of clubs //
        int countSpade = 0; //variable to count number of spades //
        int countHeart = 0; //variable to count number of hearts //
        int countDimond = 0;//variable to count number of diamonds //

        for (int i = l; i < k ; ++i) {
            if (i>=z && i<=12+z){
                C[i].editCardSuit(Club);  //set cardSuit with club//
                giveItToStack(i,countClub,C); //set card values with club//
                countClub++;

            } else if (i>12+z && i<=25+z){
                C[i].editCardSuit(Spade); //set cardSuit with spade//
                giveItToStack(i,countSpade,C); //set card values with spade//
                countSpade++;

            } else if(i>25+z && i<=38+z){
                C[i].editCardSuit(Heart); //set cardSuit with heart//
                giveItToStack(i,countHeart,C); //set card values with heart//
                countHeart++;

            } else if (i>38+z && i<= 51+z){
                C[i].editCardSuit(Diamond); //set cardSuit with Diamond//
                giveItToStack(i,countDimond,C);  //set card values with Diamond//
                countDimond++;
            }

        }
        count++;
    }

    return 0;
}

/*
 * giveItToStack(int i, int count, vector <card> &C)
 * function used to store value of card to deck
 * parameter: int i //number of card
 *	      vector<card> &C //refernce to the card
 *	      int count //counter
 * return: int // this will signify the outcome of execution of function 
 */

int giveItToStack(int i, int count, vector <card> &C){
    //function to set the card value according to the specifics of the user 'count'//
    switch (count){
        case 0 : C[i].editCardValue(Two);
            break;
        case 1 : C[i].editCardValue(Three);
            break;
        case 2 : C[i].editCardValue(Four);
            break;
        case 3 : C[i].editCardValue(Five);
            break;
        case 4 : C[i].editCardValue(Six);
            break;
        case 5 : C[i].editCardValue(Seven);
            break;
        case 6 : C[i].editCardValue(Eight);
            break;
        case 7 : C[i].editCardValue(Nine);
            break;
        case 8 : C[i].editCardValue(Ten);
            break;
        case 9 : C[i].editCardValue(Jack);
            break;
        case 10 : C[i].editCardValue(Queen);
            break;
        case 11 : C[i].editCardValue(King) ;
            break;
        case 12 : C[i].editCardValue(Ace);
    }
    return 0;
}

