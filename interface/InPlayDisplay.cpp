#include "InPlayDisplay.hpp"
using namespace std;

InPlayDisplay :: InPlayDisplay()
{
  for(int i = 0; i < 5; ++i) {
    card_value.push_back("");
    card_suit.push_back("");
  }
}

void InPlayDisplay :: updateCards(vector<string> cv, vector<string> cs)
{
  card_value = cv;
  card_suit = cs;
}

void InPlayDisplay :: draw() const
{
  drawLBorder(); drawLine1(); drawRBorder();
  drawLBorder(); drawLine2(); drawRBorder();
  drawLBorder(); drawLine3(); drawRBorder();
  drawLBorder(); drawLine4(); drawRBorder();
  drawLBorder(); drawLine5(); drawRBorder();
}

void InPlayDisplay :: drawLine1() const
{
  for(int i = 0; i < 5; ++i)
    drawTopOfCard(card_value[i]);
}
void InPlayDisplay :: drawLine2() const
{
  for(int i = 0; i < 5; ++i)
    drawCardValue(card_suit[i], card_value[i]);
}
void InPlayDisplay :: drawLine3() const
{
  for(int i = 0; i < 5; ++i)
    drawMidOfCard(card_value[i]);
}
void InPlayDisplay :: drawLine4() const
{
  for(int i = 0; i < 5; ++i)
    drawCardValue(card_value[i], card_suit[i]);
}
void InPlayDisplay :: drawLine5() const
{
  for(int i = 0; i < 5; ++i)
    drawBotOfCard(card_value[i]);
}

void InPlayDisplay :: drawLBorder() const
{
  cout << "|  ";
}
void InPlayDisplay :: drawRBorder() const
{
  repeatString(" ",18);
  cout << "|" << endl;
}
