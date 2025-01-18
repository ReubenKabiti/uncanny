#include <SDL3/SDL.h>
#include "sdl_keyboard.hpp"

namespace UC
{
  bool SDLKeyboard::isKeyDown(Key key)
  {
    const bool *state = SDL_GetKeyboardState(nullptr);
    switch (key)
    {
    case Key::A:
      return state[SDL_SCANCODE_A];
    case Key::D:
      return state[SDL_SCANCODE_D];
    case Key::S:
      return state[SDL_SCANCODE_S];
    case Key::W:
      return state[SDL_SCANCODE_W];
    }
    return false;
  }
}