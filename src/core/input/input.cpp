#include "input.hpp"
#include <memory>

namespace UC
{
  std::shared_ptr<Input> Input::getInstance()
  {
    static std::shared_ptr<Input> instance = std::shared_ptr<Input>(new Input);
    return instance;
  }
}