#include "Card.hpp"
using namespace std;


Card :: Card(card_suit_t s, card_value_t v)
  : suit(s), value(v)
{
  setCardNameAndValues();
}

card_suit_t Card :: getCardSuit() const {return suit;}
card_value_t Card :: getCardValue() const {return value;}
string Card :: getSuitSymbol() const {return suit_symbol;}
string Card :: getValueSymbol() const {return value_symbol;}
string Card :: getCardName() const {return name;}

void Card :: setCardNameAndValues()
{
  name = setValueSymbolAndReturnName() + " of " + setSuitSymbolAndReturnName();
}

string Card :: setValueSymbolAndReturnName()
{
  switch (value) {
  case ACE   : value_symbol = "A";
               return "Ace";
  case TWO   : value_symbol = "2";
               return "Two";
  case THREE : value_symbol = "3";
               return "Three";
  case FOUR  : value_symbol = "4";
               return "Four";
  case FIVE  : value_symbol = "5";
               return "Five";
  case SIX   : value_symbol = "6";
               return "Six";
  case SEVEN : value_symbol = "7";
               return "Seven";
  case EIGHT : value_symbol = "8";
               return "Eight";
  case NINE  : value_symbol = "9";
               return "Nine";
  case TEN   : value_symbol = "10";
               return "Ten";
  case JACK  : value_symbol = "J";
               return "Jack";
  case QUEEN : value_symbol = "Q";
               return "Queen";
  case KING  : value_symbol = "K";
               return "King";
  default    : value_symbol = " ";
               return "No Defined Value";
  }
}

string Card :: setSuitSymbolAndReturnName()
{
  switch (suit) {
  case SPADES   : suit_symbol = "\u2664";
                  return "Spades";
  case HEARTS   : suit_symbol = "\u2665";
                  return "Hearts";
  case DIAMONDS : suit_symbol = "\u2666";
                  return "Diamonds";
  case CLUBS    : suit_symbol = "\u2667";
                  return "Clubs";
  default       : suit_symbol = "";
                  return "No Defined Suit";
  }
}

