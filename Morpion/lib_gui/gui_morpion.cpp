#include "gui_morpion.h"

using namespace std;

GUIMorpion::GUIMorpion(std::shared_ptr<Morpion> p_morpion)
{
  morpion = p_morpion;
  init();
}

void GUIMorpion::init()
{
  printf("Richards - Morpion v0.1\n");
}

void GUIMorpion::refreshOutput()
{
  printf("\n\n\n");
  morpion->printCells();
  printf("\n");
}

int GUIMorpion::getInput()
{
  string str;
  int value;
  auto success = false;

  while(!success)
  {
    try
    {
      getline(cin, str);
      value = stoi(str);

      if(value < 1 || value > 9)
        printf("Invalid input : int must be between 1 and 9\n");
      else
      {
        value--;

        if(!morpion->isEmpty(value))
          printf("Invalid input : Cell is not empty\n");
        else
          success = true;
      }
    }
    catch(const std::invalid_argument& ia)
    {
      printf("Invalid input : not an int\n");
    }
  }

  return value;
}

