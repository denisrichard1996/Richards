#include <iostream>
#include "lib_morpion/morpion.h"
#include "lib_gui/gui_bash.h"
using namespace std;

void classicMorpion()
{
  auto morpion = make_shared<Morpion>();
  auto gui = make_shared<GUIBash>(morpion);
  morpion->reset();
}

int main(int argc, char** argv)
{
  Morpion morpion;
  morpion.reset();

  Cell* cells = morpion.getCells();
  morpion.addElement(0, PLAYER1);
  morpion.addElement(1, PLAYER1);
  morpion.addElement(8, PLAYER1);
  morpion.addElement(4, PLAYER2);
  morpion.addElement(6, PLAYER2);
  morpion.addElement(2, PLAYER2);

  morpion.printCells();

  printf("Test %d\n", morpion.getResult());

  return 0;
}

