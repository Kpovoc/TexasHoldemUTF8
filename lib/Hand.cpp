#include "Hand.hpp"
#include <iostream>
#include <algorithm>
using namespace std;

Hand::Hand(vector<Card> pc, vector<Card> bc)
  : player_cards(pc), board_cards(bc)
{
  for (vector<Card>::iterator it = board_cards.begin(); it != board_cards.end(); ++it)
    full_set.push_back(*it);
  
  for(vector<Card>::iterator it = player_cards.begin(); it != player_cards.end(); ++it)
    full_set.push_back(*it);

  full_set = sortHighToLow(full_set);
  determineBestHand();
}

hand_t Hand::getHandName() const {return name;}
string Hand::getHandNameString() const
{
  switch(name){
  case STRAIGHT_FLUSH  : return "Straight Flush";
  case FOUR_OF_A_KIND  : return "Four of a Kind";
  case FULL_HOUSE      : return "Full House";
  case FLUSH           : return "Flush";
  case STRAIGHT        : return "Straight";
  case THREE_OF_A_KIND : return "Three of a Kind";
  case TWO_PAIR        : return "Two Pairs";
  case ONE_PAIR        : return "One Pair";
  default              : return "High Card";
  }
}
vector<card_value_t> Hand::getHighCardValues() const {return high_values;} 
vector<int> Hand::getBoardCardPositionsUsed() const {return board_card_positions_used;}

void Hand::determineBestHand()
{
   if(isFlush())
     checkStraightFlush();
  //  else
  //    checkFourOfAKind();
}

void Hand::checkStraightFlush()
{
  if(fiveInSequence(working_set))
    setNameStraightFlush();
  else
    checkFourOfAKind_Flush();
}

void Hand::checkFourOfAKind_Flush()
{
  if(fourMatchingValues())
    setNameFourOfAKind();
  else
    setNameFlush();
  // else
    // checkFullHouse_Flush();
}
// 
// void Hand::checkFullHouse_Flush()
// {
//   if(threeMatchingValues())
//     checkRemainingCardsForOnePair_Flush();
//   else
//     setNameFlush();
// }
// 
// void Hand::checkRemainingCardsForOnePair_Flush()
// {
//   if(twoMatchingValues())
//     setNameFullHouse();
//   else
//     setNameFlush();
// }
// 
// void Hand::checkFourOfAKind()
// {
//   if(fourMatchingValues())
//     setNameFourOfAKind();
//   else
//     checkFullHouse();
// }
// 
// void Hand::checkFullHouse()
// {
//   if(threeMatchingValues())
//     checkRemainingCardsForOnePair_FullHouse();
//   else
//     checkStraight();
// }
// 
// void Hand::checkRemainingCardsForOnePair_FullHouse()
// {
//   if(twoMatchingValues())
//     setNameFullHouse();
//   else
//     setNameThreeOfAKind();
// }
// 
// void Hand::checkStraight()
// {
//   if(fiveInSequence())
//     setNameStraight();
//   else
//     checkTwoPair();
// }
// 
// void Hand::checkTwoPair()
// {
//   if(twoMatchingValues())
//     checkRemainingCardsForOnePair();
//   else
//     setNameHighCard();
// }
// 
// void Hand::checkRemainingCardsForOnePair()
// {
//   if(twoMatchingValues())
//     setNameTwoPairs();
//   else
//     setNameOnePair();
// }

bool Hand::isFlush()
{
  int cards_tried = 0;
  
  for(vector<Card>::iterator it = full_set.begin(); it != full_set.end(); ++it)
    if(fiveCardsSuitsMatchNextCard(it))
      return true;
    else if (cards_tried < 2)
      cards_tried += 1;
    else
      break;
  
  return false;
}
bool Hand::fiveInSequence(vector<Card> set)
{
  vector<Card> temp;
  temp.push_back(set[0]);

  for(unsigned long int i = 1; i < set.size(); ++i)
    if(valueDifferenceIsOne(*(temp.end()-1),set[i]))
      temp.push_back(set[i]);
    else if(set.size() - i >= 5){ //Ace Check
      temp.clear();
      temp.push_back(set[i]);
    } else if(temp.size() < 5)
      return(handIsLowAceStraight(set));
      
  working_set = temp;
  return true;
}
bool Hand::handIsLowAceStraight(vector<Card> set)
{
  vector<Card> temp;

  if(!(set.begin()->getValueSymbol() == "A" &&
       (set.end()-1)->getValueSymbol() == "2"))
    return false;

  temp.push_back(set[set.size() - 4]); // Should be a 5 is low Ace straight

  for(unsigned long int i = set.size() - 3; i < set.size(); ++i)
    if((temp.end()-1)->getCardValue() - set[i].getCardValue() == 1)
      temp.push_back(set[i]);
    else
      return false;

  temp.push_back(set[0]);
  working_set = temp;
  return true;
}
bool Hand::valueDifferenceIsOne(Card high, Card low)
{
  return (high.getCardValue() - low.getCardValue() == 1);
}

bool Hand::fiveCardsSuitsMatchNextCard(vector<Card>::iterator it)
{
  createMatchingSuitSetFromNextCard(it);
  return fiveCardsSuitsMatch();
}
void Hand::createMatchingSuitSetFromNextCard(vector<Card>::iterator it)
{
  for(; it != full_set.end(); ++it)
    if(working_set.empty() || nextCardSuitMatches(it))
      working_set.push_back(*it);
}
bool Hand::nextCardSuitMatches(vector<Card>::iterator it)
{
  return working_set[0].getCardSuit() == it->getCardSuit();
}
bool Hand::fiveCardsSuitsMatch()
{
  if(working_set.size() >= 5)
    return true;
  else {
    working_set.clear();
    return false;
  }
}

bool Hand::fourMatchingValues()
{
  vector<Card>set = full_set;
  int cards_tried = 0;

  for(vector<Card>::iterator it = set.begin(); it != set.end(); ++it)
    if(nextFourMatch(it, set.end()))
      return true;
    else if (cards_tried < 3)
      cards_tried += 1;
    else
      break;

  return false;
}
bool Hand::nextFourMatch(vector<Card>::iterator it,vector<Card>::iterator end)
{
  vector<Card> temp;
  temp.push_back(*it);

  for(it += 1; it != end; ++it)
    if(temp.empty() || temp[0].getCardValue() == it->getCardValue())
      temp.push_back(*it);
  
  if(temp.size() < 4)
    return false;

  working_set = temp;
  return true;
}


// TODO: replace algorithm with Quick Sort
vector<Card> Hand::sortHighToLow(vector<Card> set)
{
  vector<Card> sortedVector;
  vector<Card>::iterator comp;

  while(!set.empty()){
    comp = set.begin();

    for(vector<Card>::iterator it = set.begin() + 1; it != set.end(); ++it)
      if(comp->getCardValue() < it->getCardValue())
	comp = it;
    
    sortedVector.push_back(*comp);
    set.erase(comp);
  }

  return sortedVector;
}

void Hand::setNameStraightFlush()
{
  name = STRAIGHT_FLUSH;
  high_values.push_back(working_set[0].getCardValue());
  determineBoardCardsUsed();
}
void Hand::setNameFlush()
{
  name = FLUSH;

  for(int i = 0; i < 5; ++i)
    high_values.push_back(working_set[i].getCardValue());

  determineBoardCardsUsed();
}
void Hand::setNameFourOfAKind()
{
  name = FOUR_OF_A_KIND;
}
void Hand::determineBoardCardsUsed()
{
  for(vector<Card>::iterator it = working_set.begin(); it != working_set.end(); ++it)
    for(int i = 0; i < (int)board_cards.size(); ++i)
      if(it->getCardName() == board_cards[i].getCardName())
	board_card_positions_used.push_back(i);

  board_card_positions_used = sortVectorIntLowToHigh(board_card_positions_used);
}
/* TODO: replace algorithm with Quick Sort */
vector<int> Hand::sortVectorIntLowToHigh(vector<int> set)
{
  sort(set.begin(),set.end());
  return set;
}
