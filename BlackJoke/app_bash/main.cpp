#include <iostream>
#include "lib_blackjoke/deck.h"
#include "lib_blackjoke/stats.h"
#include <assert.h>
#include <memory>
using namespace std;

int main(int argc, char** argv)
{
  Deck d = Deck(1);
  // d.removeCard(CARD_FACE);
  // d.removeCard(CARD_FACE);
  // d.removeCard(CARD_FACE);
  // d.removeCard(CARD_FACE);
  d.print();

  Hand h = Hand();
  h.addCard(CARD_VAL6);
  h.addCard(CARD_VAL6);
  printf("%d\n", h.getResult());

  printf("hit %f\n", getStatHit(&d, &h));
  h.print();
  return 0;
}
