#include <iostream>
#include "core/application.hpp"
#include "core/constants.hpp"
#include "core/window/dummy_window/dumm_window.hpp"

#ifdef WIN
#include <windows.h>
#endif

int main()
{
  UC::Application application;
  auto window = std::make_shared<UC::DummyWindow>();

  UC::AppConfig appConfig = {};
  appConfig.title = "Uncanny";
  appConfig.width = 640;
  appConfig.height = 480;
  appConfig.window = window;

  if (!application.init(appConfig))
  {
#ifdef WIN
    MessageBoxA(
        nullptr,
        "Failed to start application, please contact the developer with this error message",
        UC::APP_INIT_ERROR,
        MB_ICONERROR);
    return 1;
#else
    std::cout << UC::APP_INIT_ERROR << '\n'
              << "Failed to start application, please contact the developer with this error message";
#endif
  }
}