#ifndef __TEXTBOXDISPLAY_H_INCLUDED__
#define __TEXTBOXDISPLAY_H_INCLUDED__

#include "GameBoard.hpp"

class TextBoxDisplay: public GameBoard
{
private:
public:
  TextBoxDisplay();
  void draw() const;
};

#endif
