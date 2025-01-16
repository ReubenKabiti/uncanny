#include "sdl_window.hpp"

namespace UC
{
  bool SDLWindow::init()
  {
    return false;
  }
  void SDLWindow::clear(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0)
  {
  }
  void SDLWindow::update()
  {
  }
  std::queue<WindowEvent> SDLWindow::pollEvents()
  {
    return std::queue<WindowEvent>();
  }
}
