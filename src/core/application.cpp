#include <iostream>
#include "application.hpp"
#include "input/Input.hpp"

namespace UC
{
  bool Application::init(AppConfig &appConfig)
  {
    m_appConfig = appConfig;
    // init all subsystems
    if (!appConfig.window->init())
      return false;
    return true;
  }

  void Application::handleWindowEvents()
  {
    auto events = m_appConfig.window->pollEvents();
    while (!events.empty())
    {
      auto event = events.front();
      events.pop();
      switch (event.getType())
      {
      case EventType::WINDOW_CLOSE:
        m_isRunning = false;
        break;
      }
    }
  }

  void Application::update()
  {
    std::cout << "is null: " << (Input::instance == nullptr) << '\n';
    if (Input::instance->isKeyDown(Key::A))
    {
      std::cout << "Key A is down!\n";
    }
  }

  void Application::render()
  {
    m_appConfig.window->clear();
    m_appConfig.window->update();
  }

  std::string_view Application::run()
  {
    m_isRunning = true;
    while (m_isRunning)
    {
      handleWindowEvents();
      update();
      render();
    }
    return "";
  }
}