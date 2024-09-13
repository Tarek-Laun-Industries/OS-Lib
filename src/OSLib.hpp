#pragma once
#include <pch.hpp>

namespace OS {
  class OS {
  public:
    virtual void OpenURL(String _url) {}
  };

  class OSLib {
  public:
#ifdef _WIN32_
    static void Init(HWND _hwnd);
#elif __LINUX__
    static void Init();
#elif __APPLE__
    static void Init();
#endif

    static void OpenURL(String _url);
  
  private:
    static OS* os;
  };
}