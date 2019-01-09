#ifndef DECK_H
#define DECK_H

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

static std::map<Card, std::string> MapToStringCard =
{
  { CARD_FACE, "Face" },
  { CARD_ACE, "Ace" },
  { CARD_VAL2, "Val2" },
  { CARD_VAL3, "Val3" },
  { CARD_VAL4, "Val4" },
  { CARD_VAL5, "Val5" },
  { CARD_VAL6, "Val6" },
  { CARD_VAL7, "Val7" },
  { CARD_VAL8, "Val8" },
  { CARD_VAL9, "Val9" },
};

struct Deck
{
public:
  Deck(int iPack);
  Deck(Deck* c);
  void reset(int iPack);
  int size();
  bool addCard(Card card);
  bool removeCard(Card card);
  virtual void print();

  int tab[10];
};

struct Hand : public Deck
{
public:
  Hand() : Deck(0) {};
  Hand(Hand* h) : Deck(static_cast<Deck*>(h)) {};
  int getResult();
  void print() override;
};

#endif
