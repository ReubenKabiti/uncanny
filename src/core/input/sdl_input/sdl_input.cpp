#include <SDL3/SDL.h>
#include <iostream>
#include "sdl_input.hpp"

namespace UC
{
  bool SDLInput::isKeyDown(Key key)
  {
    std::cout << "before\n";
    const bool *state = SDL_GetKeyboardState(NULL);
    std::cout << "is null: " << (state == nullptr) << '\n';
    bool isDown = false;
    switch (key)
    {
    case Key::W:
      isDown = state[SDL_SCANCODE_W];
    case Key::A:
      isDown = state[SDL_SCANCODE_A];
    case Key::S:
      isDown = state[SDL_SCANCODE_S];
    case Key::D:
      isDown = state[SDL_SCANCODE_D];
    case Key::ESC:
      isDown = state[SDL_SCANCODE_ESCAPE];
    }
    ::std::cout << SDL_GetError() << '\n';
    return isDown;
  }
}