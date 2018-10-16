#ifndef GUI_INTERFACE_H
#define GUI_INTERFACE_H

#include <memory>
#include "lib_morpion/morpion.h"

struct GUIInterface
{
public:
  virtual ~GUIInterface {};
  virtual void init() = 0;
  virtual void refreshOutput() = 0;
  virtual int getInput() = 0;

private:
  std::shared_ptr<Morpion> morpion;
};

#endif
