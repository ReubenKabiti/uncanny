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
  class Input
  {
  public:
    virtual ~Input() {}
    virtual bool isKeyDown(Key key) = 0;

    static void init(std::shared_ptr<Input> instance) { instance = instance; }

  public:
    static std::shared_ptr<Input> instance;
  };
}
