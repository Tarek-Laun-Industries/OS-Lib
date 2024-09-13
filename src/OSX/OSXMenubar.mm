#include <pch.hpp>
#include <OSX/OSXMenubar.hpp>

#import <Cocoa/Cocoa.h>

@interface MacOSMenuBarOC : NSObject
@end

@implementation MacOSMenuBarOC
  + (void)init {
    // Create the application menu
    NSMenu* m_menuBar = [[NSMenu alloc] initWithTitle:@""];
    [NSApp setMainMenu:m_menuBar];
  }

  + (void)addMenu:(NSString *)menuName {
    NSMenu *m_menuBar = [NSApp mainMenu];
    NSString *nsMenuTitle = [NSString stringWithUTF8String:menuName.UTF8String];
    NSMenuItem *menuBarItem = [[NSMenuItem alloc] initWithTitle:nsMenuTitle action:nil keyEquivalent:@""];
    NSMenu *menu = [[NSMenu alloc] initWithTitle:nsMenuTitle];
    [menuBarItem setSubmenu:menu];
    [m_menuBar addItem:menuBarItem];
  }

  + (void)addSubMenu:(NSString *)menuName :(NSString *)name {
    NSString *nsMenuName = [NSString stringWithUTF8String:menuName.UTF8String];
    NSArray *nsMenuNames = [nsMenuName componentsSeparatedByString:@"/"];
    NSString *nsSubMenuName = [NSString stringWithUTF8String:name.UTF8String];
    NSMenu *m_menuBar = [NSApp mainMenu];
    NSMenuItem *menuItem = [m_menuBar itemWithTitle:nsMenuNames[0]];

    for (NSUInteger i = 1; i < [nsMenuNames count]; i++) {
      NSMenu *menu = [menuItem submenu];
      NSMenuItem *newMenuItem = [menu itemWithTitle:nsMenuNames[i]];

      if (menuItem) {
        menuItem = newMenuItem;
      }else {
        NSMenuItem *subMenuItem = [[NSMenuItem alloc] initWithTitle:nsMenuNames[i] action:nil keyEquivalent:@""];
        NSMenu *subMenu = [[NSMenu alloc] initWithTitle:nsMenuNames[i]];
        [subMenuItem setSubmenu:subMenu];
        [menu addItem:subMenuItem];
        menuItem = newMenuItem;
      }
    }
    
    if (menuItem) {
      NSMenu *menu = [menuItem submenu];
      if (menu) {
        NSMenuItem *subMenuItem = [[NSMenuItem alloc] initWithTitle:nsSubMenuName action:nil keyEquivalent:@""];
        NSMenu *subMenu = [[NSMenu alloc] initWithTitle:nsSubMenuName];
        [subMenuItem setSubmenu:subMenu];
        [menu addItem:subMenuItem];
      }
    }
  }

  + (void)addSeperator:(NSString *)menuName {
    NSString *nsMenuName = [NSString stringWithUTF8String:menuName.UTF8String];
    NSArray *nsMenuNames = [nsMenuName componentsSeparatedByString:@"/"];
    NSMenu *m_menuBar = [NSApp mainMenu];

    NSMenuItem *menuItem = [m_menuBar itemWithTitle:nsMenuNames[0]];

    for (NSUInteger i = 1; i < [nsMenuNames count]; i++) {
      NSMenu *menu = [menuItem submenu];
      NSMenuItem *newMenuItem = [menu itemWithTitle:nsMenuNames[i]];

      if (menuItem) {
        menuItem = newMenuItem;
      }else {
        NSMenuItem *subMenuItem = [[NSMenuItem alloc] initWithTitle:nsMenuNames[i] action:nil keyEquivalent:@""];
        NSMenu *subMenu = [[NSMenu alloc] initWithTitle:nsMenuNames[i]];
        [subMenuItem setSubmenu:subMenu];
        [menu addItem:subMenuItem];
        menuItem = newMenuItem;
      }
    }

    if (menuItem) {
      NSMenu *menu = [menuItem submenu];
      if (menu) {
        [menu addItem:[NSMenuItem separatorItem]];
      }
    }  
  }

  + (void)handleMenuItem:(NSMenuItem*)menuItem {
    // Rufe den Callback auf, der im NSMenuItem gespeichert ist
    NSValue *value = [menuItem representedObject];
    if (value != nil) {
      std::function<void()> *callback = reinterpret_cast<std::function<void()> *>([value pointerValue]);
      if (callback != nullptr) {
        (*callback)();
      }
    }
  }

  + (void)addMenuItem:(NSString *)menuName :(NSString *)itemName :(NSString *)hotKey :(std::function<void()>)callback {
    NSMenu *m_menuBar = [NSApp mainMenu];
    NSString *nsMenuName = [NSString stringWithUTF8String:menuName.UTF8String];
    NSArray *nsMenuNames = [nsMenuName componentsSeparatedByString:@"/"];
    NSString *nsMenuItemTitle = [NSString stringWithUTF8String:itemName.UTF8String];
    NSString *nsKeyEquivalent = [NSString stringWithUTF8String:hotKey.UTF8String];
    
    // Suche nach dem Menü mit dem Titel
    NSMenuItem *menuItem = [m_menuBar itemWithTitle:nsMenuNames[0]];

    for (NSUInteger i = 1; i < [nsMenuNames count]; i++) {
      NSMenu *menu = [menuItem submenu];
      NSMenuItem *newMenuItem = [menu itemWithTitle:nsMenuNames[i]];

      if (menuItem) {
        menuItem = newMenuItem;
      }else {
        NSMenuItem *subMenuItem = [[NSMenuItem alloc] initWithTitle:nsMenuNames[i] action:nil keyEquivalent:@""];
        NSMenu *subMenu = [[NSMenu alloc] initWithTitle:nsMenuNames[i]];
        [subMenuItem setSubmenu:subMenu];
        [menu addItem:subMenuItem];
        menuItem = newMenuItem;
      }
    }

    if (menuItem) {
      NSMenu *menu = [menuItem submenu];
      if (menu) {
        // Füge das Menüelement hinzu
        NSMenuItem *newMenuItem = [[NSMenuItem alloc] initWithTitle:nsMenuItemTitle action:@selector(handleMenuItem:) keyEquivalent:nsKeyEquivalent];
        [newMenuItem setTarget:self];
        [newMenuItem setRepresentedObject:[NSValue valueWithPointer:(__bridge const void *)(new std::function<void()>(callback))]];
        [menu addItem:newMenuItem];
      }
    }
  }
@end

namespace OSLib {
    void OSXMenuBar::Init() {
      [MacOSMenuBarOC init];
    }

    void OSXMenuBar::AddMenu(String _menuName) {
      NSString *nsMenuTitle = [NSString stringWithUTF8String:_menuName.c_str()];
      // Create the menu
      [MacOSMenuBarOC addMenu:nsMenuTitle];
    }

    void OSXMenuBar::AddSubMenu(String _path, String _subMenuName) {
      NSString *nsMenuTitle = [NSString stringWithUTF8String:_path.c_str()];
      NSString *nsSubMenuTitle = [NSString stringWithUTF8String:_subMenuName.c_str()];

      // Create the sub menu
      [MacOSMenuBarOC addSubMenu:nsMenuTitle:nsSubMenuTitle];
    }

    void OSXMenuBar::AddSepperator(String _path) {
      NSString *nsMenuTitle = [NSString stringWithUTF8String:_path.c_str()];

      [MacOSMenuBarOC addSeperator:nsMenuTitle];
    }

    void OSXMenuBar::AddItem(String _path, String _itemName, String _key, std::function<void()> _callback) {
      NSString *nsMenuTitle = [NSString stringWithUTF8String:_path.c_str()];
      NSString *nsMenuItemTitle = [NSString stringWithUTF8String:_itemName.c_str()];
      NSString *nsKey = [NSString stringWithUTF8String:_key.c_str()];

      // Create the menu item
      [MacOSMenuBarOC addMenuItem:nsMenuTitle:nsMenuItemTitle:nsKey:_callback];
    }

    void OSXMenuBar::SetItemDisabled(String _path, String _itemName, bool _disabled) {

    }

    void OSXMenuBar::SetItemChecked(String _path, String _itemName, bool _checked) {

    }
}