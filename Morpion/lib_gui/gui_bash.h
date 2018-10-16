#ifndef GUI_BASH_H
#define GUI_BASH_H

#include "gui_interface.h"

struct GUIBash : public GUIInterface
{
public:
  void GUIBash(std::shared_ptr<Morpion> p_morpion);

  virtual void init();
  virtual void refreshOutput();
  virtual int getInput();
};

#endif
