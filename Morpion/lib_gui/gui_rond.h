#ifndef GUI_MORPION_ROND_H
#define GUI_MORPION_ROND_H

#include "gui_interface.h"
#include "lib_morpion/morpion_rond.h"
#include <memory>
#include <iostream>
#include <string>

struct GUIMorpionRond : public GUIInterface
{
public:
  GUIMorpionRond(std::shared_ptr<MorpionRond> p_morpion);

  virtual void init();
  virtual void refreshOutput();
  virtual int getInput();

private:
  std::shared_ptr<MorpionRond> morpionRond;
};

#endif

