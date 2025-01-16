#include "application.hpp"

namespace UC
{
  bool Application::init(AppConfig &appConfig)
  {
    m_appConfig = appConfig;
    // init all subsystems
    auto &window = appConfig.window;
    window->setTitle(appConfig.title);
    window->setWidth(appConfig.width);
    window->setHeight(appConfig.height);
    if (!appConfig.window->init())
      return false;
    return true;
  }
}