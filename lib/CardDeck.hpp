#ifndef __CARDDECK_H_INCLUDED__
#define __CARDDECK_H_INCLUDED__

#include <vector>
#include "Card.hpp"

class CardDeck
{
 private:
  std::vector<Card> masterDeck;
  std::vector<Card> deck;
  int deck_position;

  Card popNextCard();

 public:
  CardDeck();
  void shuffleDeck();
  Card drawCard();
};

#endif
