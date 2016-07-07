#ifndef __WINNINGHANDDISPLAY_H_INCLUDED__
#define __WINNINGHANDDISPLAY_H_INCLUDED__

#include "GameBoard.hpp"

class WinningHandDisplay: public GameBoard
{
private:
  std::vector<std::string> card_value;
  std::vector<std::string> card_suit;

  void drawLine1() const;
  void drawLine2() const;
  void drawLine3() const;
  void drawLine4() const;
  void drawLine5() const;

  void drawLBorder() const;
  void drawRBorder() const;
  void drawGap(int) const;
public:
  WinningHandDisplay();
  void draw() const;
  void update(std::vector<std::string> cv, std::vector<std::string> cs);
};

#endif
