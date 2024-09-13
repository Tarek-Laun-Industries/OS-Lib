#include <pch.hpp>
#include <OSX/OSX.hpp>
#include <CoreFoundation/CoreFoundation.h>
#include <Cocoa/Cocoa.h>

namespace OSLib {

  void OSX::ThrowError(String _text) {
    SInt32 nRes = 0;
    CFUserNotificationRef pDlg = NULL;
    const void* keys[] = { kCFUserNotificationAlertHeaderKey, kCFUserNotificationAlertMessageKey };
    const void* vals[] = {
      CFSTR("Error!"),
      CFStringCreateWithCString(NULL, _text.c_str(), kCFStringEncodingUTF8)
    };
    
    CFDictionaryRef dict = CFDictionaryCreate(0, keys, vals, sizeof(keys)/sizeof(*keys), &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
    
    pDlg = CFUserNotificationCreate(kCFAllocatorDefault, 0, kCFUserNotificationStopAlertLevel, &nRes, dict);
  }

  void OSX::OpenURL(String _url) {
    NSString *nsURL = [NSString stringWithUTF8String:_url.c_str()];
    NSURL *url = [NSURL URLWithString:nsURL];
    [[NSWorkspace sharedWorkspace] openURL:url];
  }
}