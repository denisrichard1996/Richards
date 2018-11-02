#include "gui_rond.h"

using namespace std;

GUIMorpionRond::GUIMorpionRond(std::shared_ptr<MorpionRond> p_morpion)
{
  morpionRond = p_morpion;
  init();
}

void GUIMorpionRond::init()
{
  printf("Richards - Morpion v0.1\n");
}

void GUIMorpionRond::refreshOutput()
{
  printf("\n\n\n");
  morpionRond->printMorpionRond();
  printf("\n");
}

int GUIMorpionRond::getInput()
{
  // string str;
  // int value;
  // auto success = false;
  //
  // while(!success)
  // {
  //   try
  //   {
  //     getline(cin, str);
  //     value = stoi(str);
  //
  //     if(value < 1 || value > 9)
  //       printf("Invalid input : int must be between 1 and 9\n");
  //     else
  //     {
  //       value--;
  //
  //       if(!morpion->isEmpty(value))
  //         printf("Invalid input : Cell is not empty\n");
  //       else
  //         success = true;
  //     }
  //   }
  //   catch(const std::invalid_argument& ia)
  //   {
  //     printf("Invalid input : not an int\n");
  //   }
  // }

  return 0;
}

