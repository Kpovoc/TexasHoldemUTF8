#include <iostream>
#include <cstdlib>
#include "GameInterface.hpp"
using namespace std;

GameInterface :: GameInterface()
  : game(),
    stats(game.getPlayerCurrentMoney(1), game.getPlayerCurrentMoney(2),
	  game.getPlayerCurrentMoney(3), game.getPlayerCurrentMoney(4),
	  100000,100000,
	  1,2,
	  100000,1000000000),
    winning_hand(),
    inplay(),
    player_hand()
    // textbox()
{}

void GameInterface :: startGame()
{
  drawBoard();
  cin.ignore();
  game.advanceGame();
  updatePlayerHand();
  drawBoard();
  cin.ignore();
  game.advanceGame();
  updateInPlayFlop();
  drawBoard();
  cin.ignore();
  game.advanceGame();
  updateInPlayTurn();
  drawBoard();
  cin.ignore();
  game.advanceGame();
  updateInPlayRiver();
  drawBoard();
  cin.ignore();
  player_hand.updateState("Win");
  drawBoard();
  cin.ignore();
  player_hand.updateState("Lose");
  drawBoard();
  // updateInPlayShowdown();
}

void GameInterface :: drawBoard()
{
  system("clear");
  stats.draw();
  winning_hand.draw();
  inplay.draw();
  player_hand.draw();
  textbox.draw();
}

void GameInterface :: updateInPlayFlop()
{
  vector<Card> board = game.getBoardCards();
  vector<string> value;
  vector<string> suit;

  for(int i = 0; i < 5; ++i)
    if(i < 3){
      value.push_back(board[i].getValueSymbol());
      suit.push_back(board[i].getSuitSymbol());
    } else {
      value.push_back("");
      suit.push_back("");
    }

  inplay.updateCards(value, suit);
}
void GameInterface :: updateInPlayTurn()
{
  vector<Card> board = game.getBoardCards();
  vector<string> value;
  vector<string> suit;

  for(int i = 0; i < 5; ++i)
    if (i < 4) {
      value.push_back(board[i].getValueSymbol());
      suit.push_back(board[i].getSuitSymbol());
    } else {
      value.push_back("");
      suit.push_back("");
    }
  
  inplay.updateCards(value, suit);
}
void GameInterface :: updateInPlayRiver()
{
  vector<Card> board = game.getBoardCards();
  vector<string> value;
  vector<string> suit;

  for(int i = 0; i < 5; ++i) {
    value.push_back(board[i].getValueSymbol());
    suit.push_back(board[i].getSuitSymbol());
  }

  inplay.updateCards(value, suit);
}
void GameInterface :: updatePlayerHand()
{
  vector<Card> hand = game.getPlayerCards(1);
  player_hand.updatePlayerHand(hand[0].getValueSymbol(),
			       hand[0].getSuitSymbol(),
			       hand[1].getValueSymbol(),
			       hand[1].getSuitSymbol());
}
