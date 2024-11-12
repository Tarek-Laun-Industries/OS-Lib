#ifdef _WIN32
#pragma once
#include <ospch.hpp>
#include <OSLib.hpp>

namespace OSLib {
  class WIN : public OS {
  public:
    void ThrowError(String _error) override;
    void OpenURL(String _url) override;

    HWND _mainWindow;
  };
}
#endif