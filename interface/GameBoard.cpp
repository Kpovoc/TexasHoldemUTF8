#include "GameBoard.hpp"
using namespace std;

GameBoard :: GameBoard(){}

void GameBoard :: repeatString(string s, int times_to_repeat) const
{
  for(int i = 0; i < times_to_repeat; ++i)
    cout << s;
}

void GameBoard :: drawTopOfCard(string card_value) const
{
  if(card_value.empty())
    cout << "        ";
  else
    cout << ",----,  ";
}

void GameBoard :: drawMidOfCard(string card_value) const
{
  if(card_value.empty())
    cout << "        ";
  else
    cout << "|    |  ";
}

void GameBoard :: drawBotOfCard(string card_value) const
{
  if(card_value.empty())
    cout << "        ";
  else
    cout << "'----'  ";
}

void GameBoard :: drawCardValue(string first_display, string second_display) const
{
  if(first_display.empty())
    cout << "        ";
  else {
    cout << "|";
    printFirstVal(first_display);
    printSecondVal(second_display);
    cout << "|  ";
  }
}

void GameBoard :: printFirstVal(string value) const
{
  if(value.length() == 2)
    cout << value;
  else
    cout << value << " ";
}

void GameBoard :: printSecondVal(string value) const
{
  if(value.length() == 2)
    cout << value;
  else
    cout << " " << value;
}
