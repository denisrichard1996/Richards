#include <iostream>
#include "lib_morpion/morpion.h"
using namespace std;

int main(int argc, char **argv)
{
  Morpion morpion;
  morpion.reset();

  Cell* cells = morpion.getCells();
  cells[0] = PLAYER1;
  cells[1] = PLAYER1;
  cells[2] = PLAYER2;
  cells[3] = PLAYER1;
  cells[4] = PLAYER2;
  cells[5] = PLAYER2;
  cells[6] = PLAYER2;
  cells[7] = PLAYER1;
  cells[8] = EMPTY;
  morpion.printCells();
  morpion.computeResult();

  printf("Test %d\n", morpion.getResult() );

  return 0;
}
