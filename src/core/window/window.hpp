#pragma once
#include <cstdint>
#include <queue>
#include <string_view>
#include "window_events.hpp"

namespace UC
{
  class Window
  {
  public:
    virtual ~Window() {}

    virtual bool init() = 0;
    virtual void clear(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0) = 0;
    virtual void update() = 0;
    virtual std::queue<WindowEvent> pollEvents() = 0;

    inline void setTitle(std::string_view &title) { m_title = title; }
    inline const std::string_view &getTitle() const { return m_title; }

    inline void setWidth(uint16_t width) { m_width = width; }
    inline uint16_t getWidth() { return m_width; }

    inline void setHeight(uint16_t height) { m_height = height; }
    inline uint16_t getHeight() { return m_height; }

  protected:
    std::string_view m_title;
    uint16_t m_width, m_height;
  };
}
