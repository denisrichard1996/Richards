#include "blackjoke.h"
#include <assert.h>

/******************************************************************************/
Deck::Deck()
{
  for(int8_t i = 0; i < 10; i++)
    tab[i] = 0;
}

/******************************************************************************/
void Deck::resetDeck(int iPack)
{
  for(int8_t i = 1; i < 10; i++)
    tab[i] = 4 * iPack;

  tab[0] = 16 * iPack;
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
void Deck::printDeck()
{
  printf("Deck :\n");

  for(int8_t i = 0; i < 10; i++)
    if(tab[i])
      printf("%s : %d\n", MapToStringCard.at((Card)i).c_str(), tab[i]);
}

