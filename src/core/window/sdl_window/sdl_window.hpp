#pragma once
#include "../window.hpp"

namespace UC
{
  class SDLWindow : public Window
  {
  public:
    bool init() override;
    void clear(uint8_t r, uint8_t g, uint8_t b) override;
    void update() override;
    std::queue<WindowEvent> pollEvents() override;
  };
}
