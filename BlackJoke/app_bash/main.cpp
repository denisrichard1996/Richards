#include <iostream>
#include "lib_blackjoke/blackjoke.h"
#include "lib_blackjoke/stats.h"
#include <assert.h>
#include <memory>
using namespace std;

int main(int argc, char** argv)
{
  Deck d = Deck(1);
  d.removeCard(CARD_FACE);
  d.removeCard(CARD_FACE);
  d.removeCard(CARD_FACE);
  d.removeCard(CARD_FACE);
  d.print();

  Hand h = Hand();
  h.addCard(CARD_VAL9);
  h.addCard(CARD_FACE);
  h.addCard(CARD_ACE);
  printf("%d\n", h.getResult());

  printf("hit %f\n", getStatHit(&d, &h));

  return 0;
}

