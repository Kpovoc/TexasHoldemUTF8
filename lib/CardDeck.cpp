#include <cstdlib>
#include "CardDeck.hpp"
using namespace std;


CardDeck :: CardDeck()
{
  for (card_suit_t i = HEARTS; i <= SPADES; i = card_suit_t(i + 1))
    for (card_value_t j = TWO; j <= ACE; j = card_value_t(j + 1))
      masterDeck.push_back(Card(i, j));

  deck = masterDeck;
}

void CardDeck :: shuffleDeck()
{
  srand(time(NULL));
  deck.clear();
  vector<Card> temp = masterDeck;
  int modifier;
  int index;

  while (!(temp.empty())) {
    modifier = temp.size();
    index = rand() % modifier;
    deck.push_back(temp[index]);
    temp.erase(temp.begin()+index);
  }
  
}

Card CardDeck :: drawCard()
{
  // TODO: throw exception when out of cards.
  return (!(deck.empty())) ? popNextCard() : Card(S_EMPTY, V_EMPTY);
}

Card CardDeck :: popNextCard()
{
  Card temp = deck.back();
  deck.pop_back();
  return temp;
}
