#include "sdl_window.hpp"

namespace UC
{
  SDLWindow::~SDLWindow()
  {
    SDL_DestroyWindow(m_window);
    SDL_Quit();
  }

  bool SDLWindow::init()
  {
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
      SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL initialization failed: %s\n", SDL_GetError());
      return false;
    }
    m_window = SDL_CreateWindow(
        getTitle().data(),
        getWidth(),
        getHeight(),
        SDL_WINDOW_RESIZABLE);

    if (m_window == NULL)
    {
      SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
      SDL_Quit();
      return false;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(m_window, NULL);
    if (renderer == NULL)
    {
      SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create renderer: %s\n", SDL_GetError());
      SDL_DestroyWindow(m_window);
      SDL_Quit();
      return false;
    }

    return true;
  }
  void SDLWindow::clear(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0)
  {
    SDL_SetRenderDrawColor(m_renderer, r, g, b, 255);
    SDL_RenderClear(m_renderer);
  }
  void SDLWindow::update()
  {
    SDL_RenderPresent(m_renderer);
  }
  std::queue<WindowEvent> SDLWindow::pollEvents()
  {
    std::queue<WindowEvent> windowEvents;
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      case SDL_EVENT_QUIT:
        windowEvents.push(WindowEvent(EventType::WINDOW_CLOSE));
        break;
      }
    }
    return windowEvents;
  }
}
