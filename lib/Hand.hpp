#ifndef __HAND_H_INCLUDED__
#define __HAND_H_INCLUDED__

#include "Card.hpp"
#include <vector>

enum hand_t{HIGH_CARD, ONE_PAIR, TWO_PAIR, THREE_OF_A_KIND, STRAIGHT,
	    FLUSH, FULL_HOUSE, FOUR_OF_A_KIND, STRAIGHT_FLUSH};

class Hand
{
private:
  hand_t name;
  std::vector<int> board_card_positions_used;
  std::vector<card_value_t> high_values; // 1 - 3 values.
  std::vector<Card> board_cards;  // 5 cards
  std::vector<Card> player_cards; // 2 cards
  std::vector<Card> working_set;
  std::vector<Card> full_set;

  void determineBestHand();
  void checkStraightFlush();
  void checkFourOfAKind();
  void checkFourOfAKind_Flush();
  void checkFullHouse();
  void checkRemainingCardsForOnePair_FullHouse();
  void checkFullHouse_Flush();
  void checkRemainingCardsForOnePair_Flush();
  void checkStraight();
  void checkTwoPair();
  void checkRemainingCardsForOnePair();

  bool isFlush();
  bool fiveInSequence(std::vector<Card>);
  bool handIsLowAceStraight(std::vector<Card>);
  bool valueDifferenceIsOne(Card high,Card low);
  bool fiveCardsSuitsMatchNextCard(std::vector<Card>::iterator);
  bool fiveCardsSuitsMatch();
  bool nextCardSuitMatches(std::vector<Card>::iterator);
  void createMatchingSuitSetFromNextCard(std::vector<Card>::iterator);

  bool fourMatchingValues();
  bool nextFourMatch(std::vector<Card>::iterator it,std::vector<Card>::iterator end);
  std::vector<Card> sortHighToLow(std::vector<Card>);

  void setNameStraightFlush();
  void setNameFlush();
  void setNameFourOfAKind();
  void determineBoardCardsUsed();
  std::vector<int> sortVectorIntLowToHigh(std::vector<int> set);
public:
  /* Copy Constructor */
  Hand(std::vector<Card> pc, std::vector<Card> bc);
  hand_t getHandName() const;
  std::string getHandNameString() const;
  std::vector<card_value_t> getHighCardValues() const;
  std::vector<int> getBoardCardPositionsUsed() const;
};

#endif
