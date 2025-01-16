#pragma once

#include "../window.hpp"

namespace UC
{
  class DummyWindow : public Window
  {
  public:
    DummyWindow();
    ~DummyWindow();

    bool init() override;
    void clear(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0) override;
    std::queue<WindowEvent> pollEvents() override;
    void update() override;
  };
}