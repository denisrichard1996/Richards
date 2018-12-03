#include <iostream>
#include "lib_blackjoke/blackjoke.h"
#include <assert.h>
#include <memory>
using namespace std;

int main(int argc, char** argv)
{
  Deck d = Deck();
  d.resetDeck(2);
  d.printDeck();
  return 0;
}

