#include "input.hpp"
namespace UC
{
  std::shared_ptr<Input> Input::getInstance()
  {
    static std::shared_ptr<Input> instance = std::make_shared<Input>();
    return instance;
  }
}