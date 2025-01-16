#pragma once
#include <string_view>
#include <memory>
#include "window/window.hpp"

namespace UC
{
  struct AppConfig
  {
    std::shared_ptr<Window> window;
  };

  class Application
  {
  public:
    bool init(AppConfig &appConfig);
    std::string_view run();

  private:
    void handleWindowEvents();
    void update();
    void render();

  private:
    AppConfig m_appConfig;
    bool m_isRunning = false;
  };
}