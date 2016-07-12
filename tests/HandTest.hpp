#ifndef __HANDTEST_H_INCLUDED__
#define __HANDTEST_H_INCLUDED__
#include "../lib/Hand.hpp"

class HandTest
{
public:
  HandTest();
  void runHandTestSuite();
private:
  Hand makeHand(Card,Card,Card,Card,Card,Card,Card);
  void test_isFlush();
  void test_isStraightFlush_AceHigh();
  void test_isStraightFlush_AceLow();
  void test_isStraightFlush_NoAce();
  void test_isFourOfAKind();
};

#endif
