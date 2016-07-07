#include "PlayerHandDisplay.hpp"
using namespace std;

PlayerHandDisplay :: PlayerHandDisplay(string c1v, string c1s,
				       string c2v, string c2s, string gs)
  : card_one_value(c1v), card_one_suit(c1s),
    card_two_value(c2v), card_two_suit(c2s),
    game_state(gs)
{}


void PlayerHandDisplay :: draw() const
{
  if(game_state == "Win")
    drawWin();
  else if(game_state == "Lose")
    drawLose();
  else
    drawOngoing();
}
void PlayerHandDisplay :: updateState(string state)
{
  game_state = state;
}
void PlayerHandDisplay :: updatePlayerHand(string c1v, string c1s,
					   string c2v, string c2s)
{
  card_one_value = c1v;
  card_one_suit = c1s;
  card_two_value = c2v;
  card_two_suit = c2s;
}

void PlayerHandDisplay :: drawWin() const
{
  drawLBorder(); drawWinLine1(); drawCardsLine1(); drawRBorder();
  drawLBorder(); drawWinLine2(); drawCardsLine2(); drawRBorder();
  drawLBorder(); drawWinLine3(); drawCardsLine3(); drawRBorder();
  drawLBorder(); drawWinLine4(); drawCardsLine4(); drawRBorder();
  drawLBorder(); drawWinLine5(); drawCardsLine5(); drawRBorder();
  drawLBorder(); repeatString(" ",60); drawRBorder();
}
void PlayerHandDisplay :: drawLose() const
{
  drawLBorder(); drawLoseLine1(); drawCardsLine1(); drawRBorder();
  drawLBorder(); drawLoseLine2(); drawCardsLine2(); drawRBorder();
  drawLBorder(); drawLoseLine3(); drawCardsLine3(); drawRBorder();
  drawLBorder(); drawLoseLine4(); drawCardsLine4(); drawRBorder();
  drawLBorder(); drawLoseLine5(); drawCardsLine5(); drawRBorder();
  drawLBorder(); repeatString(" ",60); drawRBorder();
}
void PlayerHandDisplay :: drawOngoing() const
{
  drawLBorder(); repeatString(" ",44); drawCardsLine1(); drawRBorder();
  drawLBorder(); repeatString(" ",44); drawCardsLine2(); drawRBorder();
  drawLBorder(); repeatString(" ",44); drawCardsLine3(); drawRBorder();
  drawLBorder(); repeatString(" ",44); drawCardsLine4(); drawRBorder();
  drawLBorder(); repeatString(" ",44); drawCardsLine5(); drawRBorder();
  drawLBorder(); repeatString(" ",60); drawRBorder();
}

void PlayerHandDisplay :: drawWinLine1() const
{
  cout << "     _/         _/  _/_/_/  _/      _/      ";
}
void PlayerHandDisplay :: drawWinLine2() const
{
  cout << "    _/         _/    _/    _/_/    _/       ";
}
void PlayerHandDisplay :: drawWinLine3() const
{
  cout << "   _/   _/    _/    _/    _/  _/  _/        ";
}
void PlayerHandDisplay :: drawWinLine4() const
{
  cout << "    _/ _/  _/      _/    _/    _/_/         ";
}
void PlayerHandDisplay :: drawWinLine5() const
{
  cout << "     _/ _/      _/_/_/  _/      _/          ";
}

void PlayerHandDisplay :: drawLoseLine1() const
{
  cout << "      _/         _/_/     _/_/_/  _/_/_/_/  ";
}
void PlayerHandDisplay :: drawLoseLine2() const
{
  cout << "     _/       _/    _/ _/        _/         ";
}
void PlayerHandDisplay :: drawLoseLine3() const
{
  cout << "    _/       _/    _/   _/_/    _/_/_/      ";
}
void PlayerHandDisplay :: drawLoseLine4() const
{
  cout << "   _/       _/    _/       _/  _/           ";
}
void PlayerHandDisplay :: drawLoseLine5() const
{
  cout << "  _/_/_/_/   _/_/   _/_/_/    _/_/_/_/      ";
}

void PlayerHandDisplay :: drawCardsLine1() const
{
  drawTopOfCard(card_one_value);
  drawTopOfCard(card_two_value);
}
void PlayerHandDisplay :: drawCardsLine2() const
{
  drawCardValue(card_one_suit, card_one_value);
  drawCardValue(card_two_suit, card_two_value);
}
void PlayerHandDisplay :: drawCardsLine3() const
{
  drawMidOfCard(card_one_value);
  drawMidOfCard(card_two_value);
}
void PlayerHandDisplay :: drawCardsLine4() const
{
  drawCardValue(card_one_value, card_one_suit);
  drawCardValue(card_two_value, card_two_suit);
}
void PlayerHandDisplay :: drawCardsLine5() const
{
  drawBotOfCard(card_one_value);
  drawBotOfCard(card_two_value);
}
void PlayerHandDisplay :: drawLBorder() const {cout << "|";}
void PlayerHandDisplay :: drawRBorder() const {cout << "|" << endl;}
