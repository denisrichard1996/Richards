#ifndef GUI_BASH_H
#define GUI_BASH_H

#include "gui_interface.h"
#include <memory>

struct GUIBash : public GUIInterface
{
public:
  GUIBash(std::shared_ptr<Morpion> p_morpion);

  virtual void init();
  virtual void refreshOutput();
  virtual int getInput();

private:
  std::shared_ptr<Morpion> morpion;
};

#endif

