#include "HandTest.hpp"
#include <iostream>
using namespace std;

HandTest::HandTest(){} 

void HandTest::runHandTestSuite()
{
  test_isFlush();
  test_isStraightFlush_AceHigh();
  test_isStraightFlush_AceLow();
  test_isStraightFlush_NoAce();
  test_isFourOfAKind();
}

Hand HandTest::makeHand(Card b1, Card b2, Card b3, Card b4, Card b5, Card p1, Card p2)
{
  vector<Card> board;
  vector<Card> player;

  board.push_back(b1);
  board.push_back(b2);
  board.push_back(b3);
  board.push_back(b4);
  board.push_back(b5);
  player.push_back(p1);
  player.push_back(p2);

  return Hand(board,player);
}

void HandTest::test_isFlush()
{
  Hand hand = makeHand(Card(HEARTS,TWO),
		       Card(HEARTS,THREE),
		       Card(HEARTS,KING),
		       Card(HEARTS,FIVE),
		       Card(CLUBS,FOUR),
		       Card(CLUBS,QUEEN),
		       Card(HEARTS,FOUR));
  /* 1, 2, 3, 4 */
  vector<int> board_pos = hand.getBoardCardPositionsUsed();

  if(hand.getHandName() == FLUSH &&
     hand.getHighCardValues()[0] == KING &&
     board_pos[0] == 1 &&
     board_pos[1] == 2 &&
     board_pos[2] == 3 &&
     board_pos[3] == 4)
    cout << "isFlush: PASS" << endl;
  else
    cout << "isFlush: FAIL | handName = " << hand.getHandNameString() << endl;
}
void HandTest::test_isStraightFlush_AceHigh()
{
  Hand hand = makeHand(Card(HEARTS,KING),
		       Card(DIAMONDS,THREE),
		       Card(HEARTS,ACE),
		       Card(HEARTS,QUEEN),
		       Card(HEARTS,TEN),
		       Card(HEARTS,JACK),
		       Card(CLUBS,SIX));

  vector<int>board_pos = hand.getBoardCardPositionsUsed();
  if(hand.getHandName() == STRAIGHT_FLUSH &&
     hand.getHighCardValues()[0] == ACE &&
     board_pos[0] == 0 &&
     board_pos[1] == 2 &&
     board_pos[2] == 3 &&
     board_pos[3] == 4)
    cout << "isStraightFlush_AceHigh: PASS" << endl;
  else
    cout << "isStraightFlush_AceHigh: FAIL | handName = " << hand.getHandNameString() << endl;
}
void HandTest::test_isStraightFlush_AceLow()
{
  Hand hand = makeHand(Card(HEARTS,FOUR),
		       Card(DIAMONDS,THREE),
		       Card(HEARTS,ACE),
		       Card(HEARTS,TWO),
		       Card(HEARTS,FIVE),
		       Card(HEARTS,THREE),
		       Card(CLUBS,SIX));

  if(hand.getHandName() == STRAIGHT_FLUSH)
    cout << "isStraightFlush_AceLow: PASS" << endl;
  else
    cout << "isStraightFlush_AceLow: FAIL | handName = " << hand.getHandNameString() << endl;
}
void HandTest::test_isStraightFlush_NoAce()
{
  Hand hand = makeHand(Card(SPADES,SIX),
		       Card(SPADES,EIGHT),
		       Card(HEARTS,ACE),
		       Card(HEARTS,TWO),
		       Card(SPADES,SEVEN),
		       Card(SPADES,TEN),
		       Card(SPADES,NINE));

  if(hand.getHandName() == STRAIGHT_FLUSH)
    cout << "isStraightFlush_AceLow: PASS" << endl;
  else
    cout << "isStraightFlush_AceLow: FAIL | handName = " << hand.getHandNameString() << endl;
}
void HandTest::test_isFourOfAKind()
{
  Hand hand = makeHand(Card(SPADES,SIX),
		       Card(SPADES,EIGHT),
		       Card(HEARTS,SIX),
		       Card(DIAMONDS,SIX),
		       Card(SPADES,SEVEN),
		       Card(SPADES,TEN),
		       Card(SPADES,SIX));

  if(hand.getHandName() == FOUR_OF_A_KIND)
    cout << "isFourOfAKind: PASS" << endl;
  else
    cout << "isFourOfAKind: FAIL | handName = " << hand.getHandNameString() << endl;
}
