#ifndef GUI_MORPION_ROND_H
#define GUI_MORPION_ROND_H

#include "morpion.h"
#include <iostream>
#include <string>
#include <map>

struct MorpionRond
{
public:
  MorpionRond();
  void reset();
  bool selectIndex(int index);
  bool addElement(int index, Cell player);
  Result getResult();
  void printMorpionRond();
  Morpion morpions[9];

private:
  void computeResult();
  Morpion mainMorpion;
  Result result;
  int currentIndex;
};

#endif

