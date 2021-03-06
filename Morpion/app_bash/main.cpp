#include <iostream>
#include "lib_morpion/morpion.h"
#include "lib_morpion/morpion_rond.h"
#include "lib_gui/gui_morpion.h"
#include "lib_gui/gui_rond.h"
#include <assert.h>
#include <memory>
using namespace std;

static Cell changePlayer(Cell player)
{
  if(player == Cell::PLAYER1)
    return Cell::PLAYER2;
  return Cell::PLAYER1;
}

void classicMorpion()
{
  auto morpion = make_shared<Morpion>();
  auto gui = make_shared<GUIMorpion>(morpion);
  morpion->reset();

  Cell player = Cell::PLAYER1;
  Result result = morpion->getResult();

  while(result == Result::ONGOING)
  {
    gui->refreshOutput();
    printf("%s, your turn:\n", MapToStringCell.at(player).c_str());
    auto index = gui->getInput();
    assert(morpion->addElement(index, player));
    result = morpion->getResult();
    player = changePlayer(player);
  }

  gui->refreshOutput();
  printf("Winner : %s!\n", MapToStringResult.at(result).c_str());
}

void rondMorpion()
{
  auto morpionRond = make_shared<MorpionRond>();
  auto gui = make_shared<GUIMorpionRond>(morpionRond);
  morpionRond->reset();

  gui->refreshOutput();
  // Cell player = Cell::PLAYER1;
  // Result result = morpion->getResult();
  //
  // while(result == Result::ONGOING)
  // {
  //   printf("%s, your turn:\n", MapToStringCell.at(player).c_str());
  //   auto index = gui->getInput();
  //   assert(morpion->addElement(index, player));
  //   result = morpion->getResult();
  //   player = changePlayer(player);
  // }
  //
  // gui->refreshOutput();
  // printf("Winner : %s!\n", MapToStringResult.at(result).c_str());
}

int main(int argc, char** argv)
{
  rondMorpion();

  return 0;
}

