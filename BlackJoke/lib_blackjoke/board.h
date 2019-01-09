#ifndef BOARD_H
#define BOARD_H

#include "deck.h"


struct Board
{
public:
  Board() : deck(1), hand() {};
  void reset(int iPack);
  void print();

  bool addCardDeck(Card card);
  bool removeCardDeck(Card card);
  bool addCardHand(Card card);
  bool removeCardHand(Card card);
  float getStatHit();

private:
  Deck deck;
  Hand hand;
};

#endif
