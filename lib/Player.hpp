#ifndef __PLAYER_H_INCLUDED__
#define __PLAYER_H_INCLUDED__

#include <vector>
#include <string>
#include "Card.hpp"

class Player
{
private:
  std::vector<Card> cards; // 2 Cards
  std::string name;
  int money;
public:
  Player(std::string n = "No Name Given",int m = 0);

  std::vector<Card> getCards() const;
  std::string getName() const;
  int getCurrentMoney() const;
  
  void receiveDeltCards(Card, Card);
  void addToMoney(int);
  void subtractFromMoney(int);
};

#endif
