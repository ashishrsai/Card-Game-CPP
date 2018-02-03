# Card Game CPP


The rules of the game are as follows: 
Each player initially gets 7 cards – the remaining cards are put “face down” in a stack on the table (the hidden stack). The top card of the stack is turned face up next to the hidden stack. Each player puts down a card from his hand – this card must match the topmost open card either in suit or value – i.e. if the top card is Spade-Five a player can play any other card of suit Spade or any other suit with value Five (Club-Five, Heart-Five or Diamond-Five). If a player is unable to play any card, s/he is picking up a card from the hidden stack and the game moves to the next player. Players that pick up a card cannot play this card until it is their turn again. The game is finished if one of the players has no cards left on his/her hand. If the hidden stack is empty before any player has an empty hand, the played cards are taken, shuffled and then used as the new hidden deck.

The structure of project is as follows: 

Classes and header files:-
1. Card.h : Declares the structure for the card class and its services
2. Card.cpp: Defines the structure and implementation of services 
3. Deckcard.h: Declares the structure for the deckcard class and its services.Uses object of deckProt class as a member.
4. Deckcard.cpp: Defines the structure and implementation of services for deckCard class
5. DeckProt.h Declares the structure for the DeckProt class and its services. Uses object of card class as a member.
6. DeckProt.cpp: Defines the structure and implementation of services for deckProt class
7. cardGame.h : Declares the structure for the cardGame class and its services
8. cardGame.cpp: Defines the structure for the cardGame class and its services
9. Main: program as the main thread of execution.

Working:-
1. Card class is the lowest in the hierarchy which is used by deckProt to create a deck of ‘card objects’
2. cardDeck is used by cardGame to create multiple decks as required in the game.
3. cardGame is the uppermost in hierarchy.
4. Main starts execution and uses user input to setup number of players and number of decks to be used.
5. Illegal operation highlighted in case of an invalid entry in the user parameters.
6. Sets are distributed in batches of 7 and played deck and shuffled deck is kept separately.
7. User moves according to a match in suit or value or picks up a card from a shuffled deck in case of a mismatch.
8. Deck reshuffled if its counter reaches 0 and game proceeds again
9. Game ends when any users card stack is empty.

