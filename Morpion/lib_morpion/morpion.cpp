#include "morpion.h"

Morpion::Morpion()
{
  reset();
}

void Morpion::reset()
{
  for (int i = 0; i < 9; i++)
    cells[i] = EMPTY;

  result = ONGOING;
}

Cell* Morpion::getCells()
{
  return cells;
}

Result Morpion::getResult()
{
  return result;
}

static void getLineResult(Cell cells[9], int i, bool& win1, bool& win2)
{
  int value = cells[3*i]*cells[3*i+1]*cells[3*i+2];
  if(value==1)
    win1 = true;
  if(value==8)
    win2 = true;
  return;
}

static void getColumnResult(Cell cells[9], int i, bool& win1, bool& win2)
{
  if (i>2)
    return;
  int value = cells[i]*cells[3+i]*cells[6+i];
  if(value==1)
    win1 = true;
  if(value==8)
    win2 = true;
  return;
}

static void getDiagResult(Cell cells[9], int i, bool& win1, bool& win2)
{
  if (i > 1)
    return;
  int value = cells[2*i]*cells[4]*cells[8-2*i];
  if(value==1)
    win1 = true;
  if(value==8)
    win2 = true;
  return;
}

static Result getDrawResult(Cell cells[9])
{
  int value = 1;
  for (int i = 0; i < 9; i++)
    value *= cells[i];

  if(value!=0)
    return DRAW;
  return ONGOING;
}

void Morpion::computeResult()
{
  if(getDrawResult(cells) == DRAW)
  {
    result = DRAW;
    return;
  }

  bool win1 = false, win2 = false;
  Result res;
  for (int i = 0; i < 3; i++) {
    getLineResult(cells, i, win1, win2);
    getColumnResult(cells, i, win1, win2);
    getDiagResult(cells, i, win1, win2);
  }
  if(win1&&win2)
    result = DRAW;
  else if(win1)
    result = WINNER1;
  else if(win2)
    result = WINNER2;
  else
    result = ONGOING;
  return;
}

void Morpion::printCells()
{
  printf("%d %d %d\n%d %d %d\n%d %d %d\n", cells[6],cells[7],cells[8],cells[3],cells[4],cells[5],cells[0],cells[1],cells[2]);
}
