#pragma once
#include <string_view>
#include <memory>
#include "window/window.hpp"

namespace UC
{
  struct AppConfig
  {
    std::shared_ptr<Window> window;
    std::string_view title;
    uint16_t width;
    uint16_t height;
  };

  class Application
  {
  public:
    bool init(AppConfig &appConfig);

  private:
    AppConfig m_appConfig;
  };
}