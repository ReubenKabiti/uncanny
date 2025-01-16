#pragma once
#include "../input.hpp"

namespace UC
{
  class SDLInput : public Input
  {
  public:
    bool isKeyDown(Key key) override;
  };
}
