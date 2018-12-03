#ifndef GUI_BLACKJOKE_H
#define GUI_BLACKJOKE_H

#include <iostream>
#include <string>
#include <map>

enum Card
{
  CARD_FACE = 0,
  CARD_ACE = 1,
  CARD_VAL2 = 2,
  CARD_VAL3 = 3,
  CARD_VAL4 = 4,
  CARD_VAL5 = 5,
  CARD_VAL6 = 6,
  CARD_VAL7 = 7,
  CARD_VAL8 = 8,
  CARD_VAL9 = 9
};

struct Deck
{
public:
  Deck();
  void resetDeck(int iPack);
  bool addCard(Card card);
  bool removeCard(Card card);
  void printDeck();

  int tab[10];
};

#endif

