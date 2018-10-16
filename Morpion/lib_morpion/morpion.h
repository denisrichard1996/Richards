#ifndef GUI_MORPION_H
#define GUI_MORPION_H

#include <iostream>

enum Cell
{
  EMPTY = 0, PLAYER1 = 1, PLAYER2 = 2
};
enum Result
{
  ONGOING, WINNER1, WINNER2, DRAW
};

struct Morpion
{
public:
  Morpion();
  void reset();
  bool addElement(int index, Cell player);
  Cell* getCells();
  Result getResult();
  void printCells();

private:
  void computeResult();
  Cell cells[9];
  Result result;
};

#endif
