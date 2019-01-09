#include "blackjoke.h"
#include <assert.h>

/******************************************************************************/
Deck::Deck(int iPack)
{
  this->reset(iPack);
}

/******************************************************************************/
Deck::Deck(Deck* c)
{
  for(int8_t i = 0; i < 10; i++)
    tab[i] = c->tab[i];
}

/******************************************************************************/
void Deck::reset(int iPack)
{
  for(int8_t i = 1; i < 10; i++)
    tab[i] = 4 * iPack;

  tab[0] = 16 * iPack;
}

/******************************************************************************/
int Deck::size()
{
  int s = 0;

  for(int8_t i = 0; i < 10; i++)
    s += tab[i];

  return s;
}

/******************************************************************************/
bool Deck::addCard(Card card)
{
  tab[card]++;
  return true;
}

/******************************************************************************/
bool Deck::removeCard(Card card)
{
  if(tab[card] == 0)
    return false;

  tab[card]--;
  return true;
}

/******************************************************************************/
void Deck::print()
{
  printf("Deck :\n");

  for(int8_t i = 0; i < 10; i++)
    if(tab[i])
      printf("%s : %d\n", MapToStringCard.at((Card)i).c_str(), tab[i]);
}

/******************************************************************************/
int Hand::getResult()
{
  int s = 0, s_ace = 0;

  for(int8_t i = 0; i < 10; i++)
  {
    if(i == 0)
      s += 10 * this->tab[i];
    else
      s += i * this->tab[i];

    if(i == 1)
      s_ace += this->tab[i];
  }

  while(s <= 11 && s_ace > 0)
  {
    s += 10;
    s_ace -= 1;
  }

  if(s > 22)
    s = 22;

  return s;
}
