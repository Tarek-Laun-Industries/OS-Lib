#ifdef __APPLE__
#pragma once
#include <ospch.hpp>
#include <OSLib.hpp>

namespace OSLib {
  class OSX : public OS {
  public:
    void ThrowError(OSLString _error) override;
    void OpenURL(OSLString _url) override;
  };
}
#endif