#include <ospch.hpp>
#include <OS/MenuBar.hpp>
#include <OSX/OSXMenuBar.hpp>
#include <WIN/WINMenubar.hpp>

namespace OSLib {
#ifdef _WIN32
    MenuBar* MenuBar::CreateMenuBar(HWND _window) {
        return new WINMenuBar(_window);
    }
#elif __APPLE__
  MenuBar* MenuBar::CreateMenuBar() {
      return new OSXMenuBar();
  }
#endif
}