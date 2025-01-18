#include <iostream>
#include "core/application.hpp"
#include "core/constants.hpp"
#include "core/window/sdl_window/sdl_window.hpp"
#include "core/input/input.hpp"
#include "core/input/sdl_keyboard.hpp"

#ifdef WIN
#include <windows.h>
#endif

void showError(const char *title, const char *description)
{
#ifdef WIN
  MessageBoxA(
      nullptr,
      description,
      title,
      MB_ICONERROR);
#else
  std::cout << title << '\n'
            << description << '\n';
#endif
}

int main()
{
  UC::Application application;

  auto window = std::make_shared<UC::SDLWindow>();
  window->setTitle(UC::APP_TITLE);
  window->setWidth(640);
  window->setHeight(480);

  UC::AppConfig appConfig = {};
  appConfig.window = window;

  if (!application.init(appConfig))
  {
    showError(UC::APP_INIT_ERROR, "Failed to start application, please contact the developer with this error message");
    return 1;
  }

  auto sdlKeyboard = std::make_shared<UC::SDLKeyboard>();
  UC::Input::getInstance()->setKeyboard(sdlKeyboard);

  std::string_view errorMsg = application.run();
  if (errorMsg.size())
  {
    showError(UC::RUNTIME_ERROR, errorMsg.data());
    return 1;
  }
  return 0;
}