#ifndef __INPLAYDISPLAY_H_INCLUDED__
#define __INPLAYDISPLAY_H_INCLUDED__

#include "GameBoard.hpp"

class InPlayDisplay: public GameBoard
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
  
public:
  InPlayDisplay();
  /* Vectors require size 5 */
  void updateCards(std::vector<std::string>cv, std::vector<std::string> cs);
  void draw() const;
};

#endif
