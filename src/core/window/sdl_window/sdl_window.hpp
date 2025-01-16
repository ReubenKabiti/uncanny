#pragma once
#include <SDL3/SDL.h>
#include "../window.hpp"

namespace UC
{
  class SDLWindow : public Window
  {
  public:
    ~SDLWindow();
    bool init() override;
    void clear(uint8_t r, uint8_t g, uint8_t b) override;
    void update() override;
    std::queue<WindowEvent> pollEvents() override;

    inline SDL_Window *getSDLWindow() { return m_window; }

  private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
  };
}
