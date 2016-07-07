#ifndef __GAMEINTERFACE_H_INCLUDED__
#define __GAMEINTERFACE_H_INCLUDED__

#include "../lib/Game.hpp"
#include "GameStatsDisplay.hpp"
#include "WinningHandDisplay.hpp"
#include "InPlayDisplay.hpp"
#include "PlayerHandDisplay.hpp"
#include "TextBoxDisplay.hpp"

class GameInterface
{
private:
  Game game;
  GameStatsDisplay stats;
  WinningHandDisplay winning_hand;
  InPlayDisplay inplay;
  PlayerHandDisplay player_hand;
  TextBoxDisplay textbox;
  void drawBoard();

  void updateWinningHand();
  void updateInPlayFlop();
  void updateInPlayTurn();
  void updateInPlayRiver();
  void updateInPlayShowdown();
  void updatePlayerHand();
  void drawWinningHand();
  void drawCardsInPlay();
  void drawPlayerCards();
  void drawTextDisplay();
  void drawEmptyRow();
  void drawEmptyTextRow();
  
public:
  GameInterface();
  void startGame();
  void testStuff();
};

#endif

/*
,------------------------------------------------------------,
| P1:$999999999  P2:$999999999  P3:$999999999  P4:$999999999 |
|         SB: P1 $XXXX    Ante:$XXXX    LB: P2 $XXXX         |
|                       Pot:$XXXXXXXXXX                      |
|  ,----,  ,----,  ,----,  ,----,  ,----,    ,----,  ,----,  |
|  |    |  |    |  |    |  |    |  |    |    |    |  |    |  |
|  |    |  |    |  |    |  |    |  |    |    |    |  |    |  |
|  |    |  |    |  |    |  |    |  |    |    |    |  |    |  |
|  '----'  '----'  '----'  '----'  '----'    '----'  '----'  |
|  ,----,  ,----,  ,----,  ,----,  ,----,                    |
|  |♤  7|  |♧  8|  |♥  9|  |♦ 10|  |♤  J|                    |
|  |    |  |    |  |    |  |    |  |    |                    |
|  |7  ♤|  |8  ♧|  |9  ♥|  |10 ♦|  |J  ♤|                    |
|  '----'  '----'  '----'  '----'  '----'                    | 
|                                                            |
|     _/         _/  _/_/_/  _/      _/      ,----,  ,----,  |
|    _/         _/    _/    _/_/    _/       |♧  Q|  |♥  K|  |
|   _/   _/    _/    _/    _/  _/  _/        |    |  |    |  |
|    _/ _/  _/      _/    _/    _/_/         |Q  ♧|  |K  ♥|  |
|     _/ _/      _/_/_/  _/      _/          '----'  '----'  |
|                                                            |
|____________________________________________________________|
|,----------------------------------------------------------,|
||                                                          ||
||                                                          ||
||                                                          ||
||__________________________________________________________||
'------------------------------------------------------------'

,------------------------------------------------------------,
|                                                            |
|                                                            |
|                                                            |
|  ,----,  ,----,  ,----,  ,----,  ,----,    ,----,  ,----,  |
|  |    |  |    |  |    |  |    |  |    |    |    |  |    |  |
|  |    |  |    |  |    |  |    |  |    |    |    |  |    |  |
|  |    |  |    |  |    |  |    |  |    |    |    |  |    |  |
|  '----'  '----'  '----'  '----'  '----'    '----'  '----'  |
|  ,----,  ,----,  ,----,  ,----,  ,----,                    |
|  |    |  |    |  |    |  |    |  |    |                    |
|  |    |  |    |  |    |  |    |  |    |                    |
|  |    |  |    |  |    |  |    |  |    |                    |
|  '----'  '----'  '----'  '----'  '----'                    | 
|                                                            |
|      _/         _/_/     _/_/_/  _/_/_/_/  ,----,  ,----,  |
|     _/       _/    _/ _/        _/         |    |  |    |  |
|    _/       _/    _/   _/_/    _/_/_/      |    |  |    |  |
|   _/       _/    _/       _/  _/           |    |  |    |  |
|  _/_/_/_/   _/_/   _/_/_/    _/_/_/_/      '----'  '----'  |
|                                                            |
|____________________________________________________________|
|,----------------------------------------------------------,|
||                                                          ||
||                                                          ||
||                                                          ||
||__________________________________________________________||
'------------------------------------------------------------'          


*/
