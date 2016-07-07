#ifndef __PLAYERHANDDISPLAY_H_INCLUDED__
#define __PLAYERHANDDISPLAY_H_INCLUDED__

#include "GameBoard.hpp"

class PlayerHandDisplay: public GameBoard
{
private:
  std::string card_one_value;
  std::string card_one_suit;
  std::string card_two_value;
  std::string card_two_suit;
  std::string game_state;
  
  void drawWin() const;
  void drawLose() const;
  void drawOngoing() const;

  void drawWinLine1() const;
  void drawWinLine2() const;
  void drawWinLine3() const;
  void drawWinLine4() const;
  void drawWinLine5() const;
  
  void drawLoseLine1() const;
  void drawLoseLine2() const;
  void drawLoseLine3() const;
  void drawLoseLine4() const;
  void drawLoseLine5() const;

  void drawCardsLine1() const;
  void drawCardsLine2() const;
  void drawCardsLine3() const;
  void drawCardsLine4() const;
  void drawCardsLine5() const;

  void drawLBorder() const;
  void drawRBorder() const;
public:
  /* c1v and c2v correspond to card_one_value and card_two_value.
   * They should be single or double character strings pertaining to the value.
   * Ex: Two = "2", Ten = "10", Ace = "A", King = "K"
   * c1s and c2s correspond to card_one_suit and card_two_suit.
   * They should be single character strings of the appropriate unicode character.
   * Ex: Spades = "\u2664" Hearts = "\u2665", Diamonds = "\u2666", Clubs = "\u2667"
   * gs corresponds to the game_state. It should contain either a string victory condition,
   * "Win" "Lose", or "Ongoing" if the game is still in play or just starting.
   */
  PlayerHandDisplay(std::string c1v = "",
		    std::string c1s = "",
		    std::string c2v = "",
		    std::string c2s = "",
		    std::string gs = "Ongoing");
  void draw() const;
  /* "Win" "Lose" "Ongoing" */
  void updateState(std::string);
  void updatePlayerHand(std::string c1v, std::string c1s,
			std::string c2v, std::string c2s);
};

#endif
