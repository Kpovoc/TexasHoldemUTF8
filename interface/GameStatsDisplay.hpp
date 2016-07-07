#ifndef __GAMESTATSDISPLAY_H_INCLUDED__
#define __GAMESTATSDISPLAY_H_INCLUDED__

#include "GameBoard.hpp"

class GameStatsDisplay: public GameBoard
{
private:
  int player_money[4];
  int small_blind;
  int large_blind;
  int small_blind_player;
  int large_blind_player;
  int ante;
  int pot;

  /* main draw functions */
  void drawTopBorder() const;
  void drawPlayerMoneyRow() const;
  void drawBlindsAndAnteRow() const;
  void drawPotRow() const;

  /* helpers */
  void drawPlayerMoney(int) const;
  void printFormattedMoney(int) const;
  void printExtraSpaces(int,int) const;
public:
  GameStatsDisplay(int p1m, int p2m, int p3m, int p4m,
		   int sb, int lb, int lbp, int sbp, int a, int p);
  void update(int p1m, int p2m, int p3m, int p4m, int lbp, int sbp, int p);
  void draw() const;
};

#endif
