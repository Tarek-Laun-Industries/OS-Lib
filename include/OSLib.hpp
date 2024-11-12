#pragma once
#include <ospch.hpp>

namespace OSLib {
  class OS {
  public:
    virtual void ThrowError(String _error) {}
    virtual void OpenURL(String _url) {}


  };

  class OSLib {
  public:
#ifdef _WIN32
    static void Init(HWND _hwnd);
#elif __LINUX__
    static void Init();
#elif __APPLE__
    static void Init();
#endif

    static void ThrowError(String _error);
    static void OpenURL(String _url);
  
  private:
    static OS* os;
  };
}