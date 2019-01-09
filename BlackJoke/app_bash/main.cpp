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

  b.addCardHand(CARD_VAL6);
  b.addCardHand(CARD_VAL6);

  b.print();
  return 0;
}
