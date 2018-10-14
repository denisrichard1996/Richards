#include <iostream>

enum Cell {EMPTY=0, PLAYER1=1, PLAYER2=2};
enum Result {ONGOING, WINNER1, WINNER2, DRAW};

struct Morpion
{
public:
  Morpion();
  void reset();
  Cell* getCells();
  Result getResult();
  void computeResult();
  void printCells();
private:
  Cell cells[9];
  Result result;
};
