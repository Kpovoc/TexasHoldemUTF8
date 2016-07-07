#ifndef __GAMEBOARD_H_INCLUDED__
#define __GAMEBOARD_H_INCLUDED__

#include <iostream>
#include <vector>

class GameBoard
{
private:
  void printFirstVal(std::string value) const;
  void printSecondVal(std::string value) const;
public:
  GameBoard();
  virtual void draw() const = 0;
  void repeatString(std::string,int) const;
  void drawTopOfCard(std::string card_value) const;  
  void drawMidOfCard(std::string card_value) const;
  void drawBotOfCard(std::string card_value) const;
  void drawCardValue(std::string first_display,
		     std::string second_display) const;
};

#endif
