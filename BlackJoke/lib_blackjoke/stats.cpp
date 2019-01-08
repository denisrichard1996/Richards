#include "stats.h"
#include <assert.h>

/******************************************************************************/
int getResult(Hand* hand)
{
  int s = 0, s_ace = 0;

  for(int8_t i = 0; i < 10; i++)
  {
    if(i == 0)
      s += 10 * hand->tab[i];
    else
      s += i * hand->tab[i];

    if(i == 1)
      s_ace += hand->tab[i];
  }

  while(s <= 11 && s_ace > 0)
  {
    s += 10;
    s_ace -= 1;
  }

  if(s > 22)
    s = 22;

  return s;
}

/******************************************************************************/
float getStatHit(Deck* deck, Hand* hand)
{
  (void)deck;
  (void)hand;
  return 0;
}

