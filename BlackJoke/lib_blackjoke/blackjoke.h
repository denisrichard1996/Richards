#ifndef BLACKJOKE_H
#define BLACKJOKE_H

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
  { CARD_VAL2, "Card2" },
  { CARD_VAL3, "Card3" },
  { CARD_VAL4, "Card4" },
  { CARD_VAL5, "Card5" },
  { CARD_VAL6, "Card6" },
  { CARD_VAL7, "Card7" },
  { CARD_VAL8, "Card8" },
  { CARD_VAL9, "Card9" },
};

struct Cards
{
public:
  Cards();
  bool addCard(Card card);
  bool removeCard(Card card);
  void copy(Cards* c);
  int size();
  void print();

  int tab[10];
};

struct Deck : public Cards
{
public:
  Deck(int iPack);
  Deck(Deck* d);
  void reset(int iPack);
};

struct Hand : public Cards
{
public:
  Hand();
  Hand(Hand* h);
  void reset();
  int getResult();
};

#endif

