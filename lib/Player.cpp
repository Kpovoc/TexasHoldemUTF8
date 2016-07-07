#include "Player.hpp"
using namespace std;


Player :: Player(string n,int m)
  : name(n), money(m)
{}

void Player :: receiveDeltCards(Card card1, Card card2)
{
  cards.push_back(card1);
  cards.push_back(card2);
}

void Player :: addToMoney(int amount){money += amount;}
void Player :: subtractFromMoney(int amount){money -= amount;}

vector<Card> Player :: getCards() const {return cards;}
string Player :: getName() const {return name;}
int Player :: getCurrentMoney() const {return money;}
