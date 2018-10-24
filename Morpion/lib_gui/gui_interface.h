#ifndef GUI_INTERFACE_H
#define GUI_INTERFACE_H

#include "lib_morpion/morpion.h"

struct GUIInterface
{
  virtual ~GUIInterface() {};
  virtual void init() = 0;
  virtual void refreshOutput() = 0;
  virtual int getInput() = 0;
};

#endif

