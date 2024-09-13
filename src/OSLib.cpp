#include <pch.hpp>
#include <OSLib.hpp>

#ifdef __WIN32__

#elif __LINUX__

#elif __APPLE__
#include <OSX/OSX.hpp>
#endif

namespace OS {

  OS* OSLib::os = nullptr;

#ifdef __WIN32__
  void OSLib::Init(HWND _hwnd) {
    // Windows specific code
  }
#elif __LINUX__
  void OSLib::Init() {
    // Linux specific code
  }
#elif __APPLE__
  void OSLib::Init() {
    os = new OSX();
  }
#endif

  void OSLib::OpenURL(String _url) {
    // Open the URL
  }
}