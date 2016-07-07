#ifndef __CARD_H_INCLUDED__
#define __CARD_H_INCLUDED__

#include <string>

enum card_suit_t {S_EMPTY, HEARTS, CLUBS, DIAMONDS, SPADES};
enum card_value_t {V_EMPTY, ACE, TWO, THREE, FOUR, FIVE, SIX,
		   SEVEN,EIGHT, NINE, TEN, JACK, QUEEN, KING};
class Card
{
 private:
  card_suit_t suit;
  card_value_t value;
  std::string name;
  std::string value_symbol;
  std::string suit_symbol;

  void setCardNameAndValues();
  std::string setValueSymbolAndReturnName();
  std::string setSuitSymbolAndReturnName();

 public:
  Card(card_suit_t s = S_EMPTY, card_value_t v = V_EMPTY);
  card_suit_t getCardSuit() const;
  card_value_t getCardValue() const;
  std::string getSuitSymbol() const;
  std::string getValueSymbol() const;
  std::string getCardName() const;
};

#endif
