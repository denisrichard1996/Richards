#ifndef BOARD_H
#define BOARD_H

#include "deck.h"

float getStatHit(Deck* deck, Hand* hand);

struct Board
{
public:
  Board() : deck(1), hand() {};
  void reset(int iPack);
  void print();

  Deck deck;
  Hand hand;
};

#endif
