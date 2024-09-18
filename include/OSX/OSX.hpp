#ifdef __APPLE__
#pragma once
#include <ospch.hpp>
#include <OSLib.hpp>

namespace OSLib {
  class OSX : public OS {
  public:
    void ThrowError(String _error) override;
    void OpenURL(String _url) override;
  };
}
#endif