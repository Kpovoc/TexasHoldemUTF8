#include "WinningHandDisplay.hpp"
using namespace std;

WinningHandDisplay :: WinningHandDisplay()
{
  for(int i = 0; i<7; ++i) {
    card_value.push_back(".");
    card_suit.push_back(".");
  }
}

void WinningHandDisplay :: draw() const
{
  drawLBorder(); drawLine1(); drawRBorder();
  drawLBorder(); drawLine2(); drawRBorder();
  drawLBorder(); drawLine3(); drawRBorder();
  drawLBorder(); drawLine4(); drawRBorder();
  drawLBorder(); drawLine5(); drawRBorder();

  // for loop through values.
}

void WinningHandDisplay :: update(vector<string> cv, vector<string> cs)
{
  card_value = cv;
  card_suit = cs;
}

void WinningHandDisplay :: drawLine1() const
{
  for(int i = 0; i < 7; ++i) {
    drawTopOfCard(card_value[i]);
    drawGap(i);
  }
}
void WinningHandDisplay :: drawLine2() const
{
  for(int i = 0; i < 7; ++i) {
    drawCardValue(card_suit[i], card_value[i]);
    drawGap(i);
  }
}
void WinningHandDisplay :: drawLine3() const
{
  for(int i = 0; i < 7; ++i) {
    drawMidOfCard(card_value[i]);
    drawGap(i);
  }
}
void WinningHandDisplay :: drawLine4() const
{
  for(int i = 0; i < 7; ++i) {
    drawCardValue(card_value[i], card_suit[i]);
    drawGap(i);
  }
}
void WinningHandDisplay :: drawLine5() const
{
  for(int i = 0; i < 7; ++i) {
    drawBotOfCard(card_value[i]);
    drawGap(i);
  }
}

void WinningHandDisplay :: drawLBorder() const
{
  cout << "|  ";
}
void WinningHandDisplay :: drawRBorder() const
{
  cout << "|" << endl;
}
void WinningHandDisplay :: drawGap(int i) const
{
  if(i == 4)
    cout << "  ";
}
