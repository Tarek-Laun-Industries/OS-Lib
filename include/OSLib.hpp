#pragma once
#include <ospch.hpp>

namespace OSLib {
  class OS {
  public:
    virtual void ThrowError(OSLString _error) {}
    virtual void OpenURL(OSLString _url) {}


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

    static void ThrowError(OSLString _error);
    static void OpenURL(OSLString _url);
  
  private:
    static OS* os;
  };
}