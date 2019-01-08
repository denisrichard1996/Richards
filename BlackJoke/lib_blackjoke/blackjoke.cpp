#include "blackjoke.h"
#include <assert.h>

/******************************************************************************/
Cards::Cards()
{
  for(int8_t i = 0; i < 10; i++)
    tab[i] = 0;
}

/******************************************************************************/
Deck::Deck(int iPack)
{
  Cards();
  this->reset(iPack);
}

/******************************************************************************/
void Deck::reset(int iPack)
{
  for(int8_t i = 1; i < 10; i++)
    tab[i] = 4 * iPack;

  tab[0] = 16 * iPack;
}

/******************************************************************************/
Hand::Hand()
{
  Cards();
  this->reset();
}

/******************************************************************************/
void Hand::reset()
{
  for(int8_t i = 0; i < 10; i++)
    tab[i] = 0;
}

/******************************************************************************/
int Cards::size()
{
  int s = 0;

  for(int8_t i = 0; i < 10; i++)
    s += tab[i];

  return s;
}

/******************************************************************************/
bool Cards::addCard(Card card)
{
  tab[card]++;
  return true;
}

/******************************************************************************/
bool Cards::removeCard(Card card)
{
  if(tab[card] == 0)
    return false;

  tab[card]--;
  return true;
}

/******************************************************************************/
void Cards::print()
{
  printf("Deck :\n");

  for(int8_t i = 0; i < 10; i++)
    if(tab[i])
      printf("%s : %d\n", MapToStringCard.at((Card)i).c_str(), tab[i]);
}

