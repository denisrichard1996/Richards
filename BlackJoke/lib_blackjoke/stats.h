#ifndef STATS_H
#define STATS_H

#include "blackjoke.h"

enum Result
{
  RESULT_VALID = 0,
  RESULT_INVALID = 1,
  RESULT_BLACKJACK = 2
};

int getResult(Hand* hand);

float getStatHit(Deck* deck, Hand* hand);

#endif

