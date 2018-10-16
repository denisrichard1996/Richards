#include "gui_bash.h"

void GUIBash(std::shared_ptr<Morpion> p_morpion){
  morpion = p_morpion;
}

void GUIBash::init()
{
  printf("init\n" );
}

void GUIBash::refreshOutput()
{
  printf("refreshoutput\n" );
}

int GUIBash::getInput()
{
  return 0;
}
