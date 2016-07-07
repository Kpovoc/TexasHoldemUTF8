#include "Game.hpp"
using namespace std;


Game :: Game()
  : state(EMPTY)
{
  deck.shuffleDeck();
  players.push_back(Player("Player One",10000));
  players.push_back(Player("Player Two",10000));
  players.push_back(Player("Player Three",10000));
  players.push_back(Player("Player Four",10000));
}

game_state_t Game :: getGameState() const {return state;}
vector<Card> Game :: getBoardCards() const {return board_cards;}
vector<Card> Game :: getWinningCards() const {return winning_cards;}
vector<Card> Game :: getPlayerCards(int player_seat) const
{
  return players[player_seat - 1].getCards();
}
int Game :: getPlayerCurrentMoney(int player_seat) const
{
  return players[player_seat - 1].getCurrentMoney();
}


void Game :: advanceGame()
{ 
  switch(state) {
  case EMPTY : state = PREFLOP;
    runPreflop();
    break;
  case PREFLOP : state = FLOP;
    runFlop();
    break;
  case FLOP : state = TURN;
    runTurnOrRiver();
    break;
  case TURN : state = RIVER;
    runTurnOrRiver();
    break;
  case RIVER : state = SHOWDOWN;
    runShowdown();
    break;
  case SHOWDOWN : state = EMPTY;
    runNextRound();
    break;
  }
}

void Game :: runPreflop()
{
  dealCards();
}

void Game :: runFlop()
{
  dealTheFlop();
}

void Game :: runTurnOrRiver()
{
  burnAndDealToBoard();
}

void Game :: runShowdown()
{
  determineWinner();
}

void Game :: runNextRound()
{
  deck.shuffleDeck();
}

void Game :: dealCards()
{
  for (vector<Player>::iterator it = players.begin(); it != players.end(); ++it)
    it->receiveDeltCards(deck.drawCard(), deck.drawCard());
}

void Game :: dealTheFlop()
{
  Card burn = deck.drawCard();

  for (int i = 0; i < 3; ++i)
    board_cards.push_back(deck.drawCard());
}

void Game :: burnAndDealToBoard()
{
  Card burn = deck.drawCard();
  board_cards.push_back(deck.drawCard());
}

void Game :: determineWinner()
{
  winner = "Player One";
}
