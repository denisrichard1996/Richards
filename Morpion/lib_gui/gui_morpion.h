#ifndef GUI_MORPION_H
#define GUI_MORPION_H

#include "gui_interface.h"
#include "lib_morpion/morpion.h"
#include <memory>
#include <iostream>
#include <string>

struct GUIMorpion : public GUIInterface
{
public:
  GUIMorpion(std::shared_ptr<Morpion> p_morpion);

  virtual void init();
  virtual void refreshOutput();
  virtual int getInput();

private:
  std::shared_ptr<Morpion> morpion;
};

#endif

