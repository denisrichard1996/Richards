#ifndef GUI_MORPION_H
#define GUI_MORPION_H

#include <iostream>
#include <string>
#include <map>

enum Cell
{
  EMPTY = 0, PLAYER1 = 1, PLAYER2 = 2, FULL = 3
};

static std::map<Cell, std::string> MapToStringCell =
{
  { EMPTY, "No Player" },
  { PLAYER1, "Player 1" },
  { PLAYER2, "Player 2" },
  { FULL, "No one" }
};

enum Result
{
  ONGOING, WINNER1, WINNER2, DRAW
};

static std::map<Result, std::string> MapToStringResult =
{
  { ONGOING, "Still Ongoing" },
  { WINNER1, "Player 1" },
  { WINNER2, "Player 2" },
  { DRAW, "Draw" }
};

static std::map<Result, Cell> MapToCellResult =
{
  { ONGOING, EMPTY },
  { WINNER1, PLAYER1 },
  { WINNER2, PLAYER2 },
  { DRAW, FULL }
};

struct Morpion
{
public:
  Morpion();
  void reset();
  bool addElement(int index, Cell player);
  bool isEmpty(int index);
  Cell* getCells();
  Result getResult();
  void printCells();

private:
  void computeResult();
  Cell cells[9];
  Result result;
};

#endif

