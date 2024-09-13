#ifdef __APPLE__
#pragma once
#include <pch.hpp>
#include <OSLib.hpp>

namespace OS {
  class OSX : public OS {
  public:
    void OpenURL(String _url) override;
  };
}
#endif