#include "GameStatsDisplay.hpp"
using namespace std;

GameStatsDisplay :: GameStatsDisplay(int p1m, int p2m, int p3m, int p4m,
				     int sb, int lb, int lbp, int sbp, int a, int p)
  : small_blind(sb), large_blind(lb), small_blind_player(sbp),
    large_blind_player(lbp), ante(a), pot(p)
{
  player_money[0] = p1m;
  player_money[1] = p2m;
  player_money[2] = p3m;
  player_money[3] = p4m;
}

void GameStatsDisplay :: update(int p1m, int p2m, int p3m, int p4m,
				int lbp, int sbp, int p)
{
  player_money[0] = p1m;
  player_money[1] = p2m;
  player_money[2] = p3m;
  player_money[3] = p4m;
  small_blind_player = sbp;
  large_blind_player = lbp;
  pot = p;
}

void GameStatsDisplay :: draw() const
{
  drawTopBorder();
  drawPlayerMoneyRow();
  drawBlindsAndAnteRow();
  drawPotRow();
}
void GameStatsDisplay :: drawTopBorder() const
{
  cout << ",";
  repeatString("-", 60);
  cout << "," << endl;
}
void GameStatsDisplay :: drawPlayerMoneyRow() const
{
  cout << "|";
  
  for(int i = 0; i < 4; ++i)
    drawPlayerMoney(i);

  cout << "|" << endl;
}
void GameStatsDisplay :: drawBlindsAndAnteRow() const
{
  cout << "|";
  repeatString(" ",6);
  cout << "SB: P" << small_blind_player << " $" << small_blind;
  printExtraSpaces(small_blind,6);
  cout << "    Ante:$" << ante;
  printExtraSpaces(ante,6);
  cout << "    LB: P" << large_blind_player << " $" << large_blind;
  printExtraSpaces(large_blind, 6);
  repeatString(" ",6);
  cout << "|" << endl;
}
void GameStatsDisplay :: drawPotRow() const
{
  cout << "|";
  repeatString(" ",23);
  cout << "Pot:$" << pot;
  printExtraSpaces(pot, 10);
  repeatString(" ",22);
  cout << "|" << endl;
}

void GameStatsDisplay :: drawPlayerMoney(int player) const
{
  cout << " P" << player+1 << ":$";
  printFormattedMoney(player_money[player]);
  cout << " ";
}
void GameStatsDisplay :: printFormattedMoney(int money) const
{
  cout << money;
  printExtraSpaces(money,9);
}

void GameStatsDisplay :: printExtraSpaces(int num, int total_characters) const
{
  while (num > 9){
    total_characters -= 1;
    num /= 10;
  }
  
  for(;total_characters > 1; --total_characters)
    cout << " ";
}
