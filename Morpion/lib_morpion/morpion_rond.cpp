#include "morpion_rond.h"
#include <assert.h>

using namespace std;

/******************************************************************************/
MorpionRond::MorpionRond()
{
  reset();
}

/******************************************************************************/
void MorpionRond::reset()
{
  for(int i = 0; i < 9; i++)
    morpions[i].reset();

  mainMorpion.reset();

  result = ONGOING;
  currentIndex = -1;
}

/******************************************************************************/
bool MorpionRond::selectIndex(int index)
{
  if(index < 0 || index > 8 || morpions[index].getResult() != Result::ONGOING)
    return false;
  currentIndex = index;
  return true;
}

/******************************************************************************/
bool MorpionRond::addElement(int index, Cell player)
{
  assert(currentIndex >= 0 && currentIndex <= 8);
  assert(index >= 0 && index <= 8);
  auto success = morpions[currentIndex].addElement(index, player);

  if(!success)
    return false;
  currentIndex = (morpions[index].getResult() == Result::ONGOING) ? index : -1;
  return true;
}

/******************************************************************************/
Result MorpionRond::getResult()
{
  computeResult();
  return result;
}

/******************************************************************************/
void MorpionRond::printMorpionRond()
{
  for(int i = 0; i < 3; i++)
  {
    auto C1 = morpions[6 - 3 * i], C2 = morpions[7 - 3 * i], C3 = morpions[8 - 3 * i];
    printf("+===+===+===+\n");
    printf("|%d%d%d|%d%d%d|%d%d%d|\n", C1.getCells()[6], C1.getCells()[7], C1.getCells()[8], C2.getCells()[6], C2.getCells()[7], C2.getCells()[8], C3.getCells()[6], C3.getCells()[7], C3.getCells()[8]);
    printf("|%d%d%d|%d%d%d|%d%d%d|\n", C1.getCells()[3], C1.getCells()[4], C1.getCells()[5], C2.getCells()[3], C2.getCells()[4], C2.getCells()[5], C3.getCells()[3], C3.getCells()[4], C3.getCells()[5]);
    printf("|%d%d%d|%d%d%d|%d%d%d|\n", C1.getCells()[0], C1.getCells()[1], C1.getCells()[2], C2.getCells()[0], C2.getCells()[1], C2.getCells()[2], C3.getCells()[0], C3.getCells()[1], C3.getCells()[2]);
  }

  printf("+===+===+===+\n");
}

/******************************************************************************/
void MorpionRond::computeResult()
{
  Cell* mainCells = mainMorpion.getCells();

  for(int i = 0; i < 9; i++)
  {
    auto res = morpions[i].getResult();
    mainCells[i] = MapToCellResult.at(res);
  }

  mainMorpion.getResult();
}

