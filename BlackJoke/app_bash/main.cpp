#include <iostream>
#include "lib_blackjoke/deck.h"
#include "lib_blackjoke/board.h"
#include <assert.h>
#include <memory>
using namespace std;

int main(int argc, char** argv)
{
  Board b = Board();
  b.reset(1);

  // b.deck.removeCard(CARD_FACE);
  // b.deck.removeCard(CARD_FACE);
  // b.deck.removeCard(CARD_FACE);
  // b.deck.removeCard(CARD_FACE);

  b.hand.addCard(CARD_VAL6);
  b.hand.addCard(CARD_VAL6);

  b.print();
  return 0;
}
