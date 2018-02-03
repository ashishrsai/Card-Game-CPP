/*
 * deckProt.h
 * Structure of deckProt.h header file
 * author: Ashish Rajendra Kumar Sai
 */

#ifndef CARDGAME_DECKPROT_H   //guard for header file
#define CARDGAME_DECKPROT_H
class deckProt{
    //class definition
public:
    int setNum;  //variable to set number of deck
public:
    vector <card> Cards; //card object of type vector
    int returnSetNum();  // return setNum value in game
    vector <card> returnCard(); //returns a card
    int modifySetNum(int valueToSet); // modify the card value and set it as specified
    bool emptyTheCardDeck(){  // empty the  card deck
        Cards.empty();
    }

};


#endif //end of guard CARDGAME_DECKPROT_H
