#include "dummy_window.hpp"
#include <iostream>

namespace UC
{
  DummyWindow::DummyWindow()
  {
  }

  DummyWindow::~DummyWindow()
  {
  }

  bool DummyWindow::init()
  {
    std::cout << "Initializing window...\n";
    std::cout << "Width: " << getWidth() << '\n';
    std::cout << "Height: " << getHeight() << '\n';
    std::cout << "Title: " << getTitle() << '\n';
    return true;
  }

  void DummyWindow::clear(uint8_t r, uint8_t, uint8_t b)
  {
    std::cout << "clearing the window\n";
  }

  std::queue<WindowEvent> DummyWindow::pollEvents()
  {
    return std::queue<WindowEvent>();
  }

  void DummyWindow::update()
  {
    std::cout << "Updating the window!\n";
  }
}