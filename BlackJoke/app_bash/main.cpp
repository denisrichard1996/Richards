#include <iostream>
#include "lib_blackjoke/blackjoke.h"
#include "lib_blackjoke/stats.h"
#include <assert.h>
#include <memory>
using namespace std;

int main(int argc, char** argv)
{
  Deck d = Deck(1);
  d.print();

  Hand h = Hand();
  h.addCard(CARD_VAL4);
  h.addCard(CARD_FACE);
  h.addCard(CARD_ACE);
  printf("%d\n", getResult(&h));
  return 0;
}

