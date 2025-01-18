#pragma once
#include "input.hpp"

namespace UC
{

  class SDLKeyboard : public Keyboard
  {
  public:
    bool isKeyDown(Key key) override;
  };
}