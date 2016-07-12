#include "TestHand.hpp"
#include <iostream>
using namespace std;

// TestHand::TestHand(){} 

// void TestHand::runHandTestSuite()
// {
  // test_isFlush();
  // test_isStraightFlush_AceHigh();
  // test_isStraightFlush_AceLow();
  // test_isStraightFlush_NoAce();
// }

// Hand TestHand::makeHand(Card b1, Card b2, Card b3, Card b4, Card b5, Card p1, Card p2)
// {
  // vector<Card> board;
  // vector<Card> player;

  // board.push_back(b1);
  // board.push_back(b2);
  // board.push_back(b3);
  // board.push_back(b4);
  // board.push_back(b5);
  // player.push_back(p1);
  // player.push_back(p2);

  // return Hand(board,player);
// }

// void TestHand::test_isFlush()
// {
  // Hand hand = makeHand(Card(HEARTS,TWO),
		       // Card(HEARTS,THREE),
		       // Card(HEARTS,KING),
		       // Card(HEARTS,FIVE),
		       // Card(HEARTS,FOUR),
		       // Card(CLUBS,QUEEN),
		       // Card(HEARTS,FOUR));
  // vector<Card> board;
  // vector<Card> player;

  // board.push_back(Card(HEARTS,TWO));
  // board.push_back(Card(HEARTS,THREE));
  // board.push_back(Card(HEARTS,KING));
  // board.push_back(Card(HEARTS,FIVE));
  // board.push_back(Card(HEARTS,FOUR));
  // player.push_back(Card(CLUBS,QUEEN));
  // player.push_back(Card(HEARTS,FOUR));

  // Hand hand(board,player);

  // if(hand.getHandName() == FLUSH)
    // cout << "isFlush: PASS" << endl;
  // else
    // cout << "isFlush: FAIL | handName = " << hand.getHandNameString() << endl;
// }
// void TestHand::test_isStraightFlush_AceHigh()
// {
  // Hand hand = makeHand(Card(HEARTS,KING),
		       // Card(DIAMONDS,THREE),
		       // Card(HEARTS,ACE),
		       // Card(HEARTS,QUEEN),
		       // Card(HEARTS,TEN),
		       // Card(HEARTS,JACK),
		       // Card(CLUBS,SIX));

  // if(hand.getHandName() == STRAIGHT_FLUSH)
    // cout << "isStraightFlush: PASS" << endl;
  // else
    // cout << "isStraightFlush: FAIL | handName = " << hand.getHandNameString() << endl;
// }
