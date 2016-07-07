#include <iostream>
#include "interface/GameInterface.hpp"
using namespace std;

void printCards(vector<Card> cards)
{
  for (vector<Card>::iterator it = cards.begin(); it != cards.end(); ++it){
    Card card = *it;
    cout << card.getCardName() << ", ";
  }
  cout << endl;
}

int main()
{
  GameInterface game = GameInterface();
  game.startGame();

  // string test = "";
  
  return 0;
}
