#include <ospch.hpp>
#include <OSLib.hpp>

#ifdef __WIN32__

#elif __LINUX__

#elif __APPLE__
#include <OSX/OSX.hpp>
#endif

namespace OSLib {

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

  void OSLib::ThrowError(String _error) {
    os->ThrowError(_error);
  }

  void OSLib::OpenURL(String _url) {
    os->OpenURL(_url);
  }
}