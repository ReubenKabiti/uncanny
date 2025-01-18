#pragma once
#include <memory>

namespace UC
{
  enum class Key
  {
    W,
    A,
    S,
    D,
    ESC,
  };

  class Keyboard
  {
  public:
    virtual ~Keyboard() {}
    virtual bool isKeyDown(Key key) = 0;
  };

  class Input
  {
  public:
    ~Input() {}
    inline bool isKeyDown(Key key) { return m_keyboard->isKeyDown(key); }

    static std::shared_ptr<Input> getInstance();

    inline void setKeyboard(const std::shared_ptr<Keyboard> &keyboard) { m_keyboard = keyboard; }

  private:
    Input() {}

    std::shared_ptr<Keyboard> m_keyboard;
  };
}
