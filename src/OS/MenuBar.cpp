#include <ospch.hpp>
#include <OS/MenuBar.hpp>
#include <OSX/OSXMenuBar.hpp>

namespace OSLib {
  MenuBar* MenuBar::CreateMenuBar() {
    #ifdef __APPLE__
      return new OSXMenuBar();
    #endif
  }
}