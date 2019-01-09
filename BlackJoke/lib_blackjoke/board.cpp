#include "board.h"
#include <assert.h>

/******************************************************************************/
void Board::reset(int iPack)
{
  deck.reset(iPack);
  hand.reset(0);
}

/******************************************************************************/
void Board::print()
{
  deck.print();
  hand.print();
  printf("Score : %d   Hit? : %f\n", hand.getResult(), getStatHit(&deck, &hand));
}


/******************************************************************************/
float getStatHit(Deck* deck, Hand* hand)
{
  if(hand->getResult() >= 21 && deck->size() == 0)
    return 0.0;

  int s_hit = 0, s_miss = 0;
  Hand h_stat = Hand(hand);

  for(int8_t i = 0; i < 10; i++)
  {
    h_stat.addCard((Card)i);

    if(h_stat.getResult() <= 21)
      s_hit += deck->tab[i];
    else
      s_miss += deck->tab[i];
    h_stat.removeCard((Card)i);
  }

  return ((float)s_hit) / (s_hit + s_miss);
}
