#ifndef __GAME_H_INCLUDED__
#define __GAME_H_INCLUDED__

#include "CardDeck.hpp"
#include "Player.hpp"

enum game_state_t {EMPTY, PREFLOP, FLOP, TURN, RIVER, SHOWDOWN, EXIT};

class Game
{
private:
  CardDeck deck;
  std::vector<Player> players;
  std::string winner;
  std::vector<Card> board_cards;      // 5 Cards
  std::vector<Card> winning_cards;    // 5 Cards
  game_state_t state;

  /* Game State Functions */
  void runPreflop();
  void runFlop();
  void runTurnOrRiver();
  void runRiver();
  void runShowdown();
  void runNextRound();

  /* Helper Functions */
  void dealCards();
  void dealTheFlop();
  void burnAndDealToBoard();
  void determineWinner();
  
public:
  Game();
  game_state_t getGameState() const;
  std::vector<Card> getBoardCards() const;
  std::vector<Card> getWinningCards() const;
  std::vector<Card> getPlayerCards(int) const;
  int getPlayerCurrentMoney(int) const;

  void advanceGame();
};

#endif
