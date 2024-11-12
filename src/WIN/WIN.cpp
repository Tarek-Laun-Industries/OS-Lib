#ifdef _WIN32
#include <ospch.hpp>
#include "WIN/WIN.hpp"

namespace OSLib {

  void WIN::ThrowError(String _text) {
      MessageBox(0, _text.c_str(), "Error", MB_OK | MB_ICONERROR);
  }

  void WIN::OpenURL(String _url) {
      ShellExecute(0, 0, _url.c_str(), 0, 0, SW_SHOW);
  }
}
#endif