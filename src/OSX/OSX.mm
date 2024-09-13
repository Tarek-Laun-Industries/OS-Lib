#include <pch.hpp>
#include <OSX/OSX.hpp>
#include <CoreFoundation/CoreFoundation.h>
#include <Cocoa/Cocoa.h>

namespace OS {
  void OSX::OpenURL(String _url) {
    NSString *nsURL = [NSString stringWithUTF8String:_url.c_str()];
    NSURL *url = [NSURL URLWithString:nsURL];
    [[NSWorkspace sharedWorkspace] openURL:url];
  }
}