#pragma once
#include <ospch.hpp>

namespace OSLib {
  class MenuBar {
  public:
    virtual void Init() {}

    virtual void AddMenu(OSLString _menuName) {}
    virtual void AddSubMenu(OSLString _path, OSLString _subMenuName) {}
    virtual void AddSepperator(OSLString _path) {}
    virtual void AddItem(OSLString _path, OSLString _itemName, OSLString _key, std::function<void()> _callback) {}

    virtual void SetItemDisabled(OSLString _path, OSLString _itemName, bool _disabled) {}
    virtual void SetItemChecked(OSLString _path, OSLString _itemName, bool _checked) {}

#ifdef _WIN32
    virtual void RunCallbacks(uint32_t _function) {}
    static MenuBar* CreateMenuBar(HWND _window);
#elif __APPLE__
    static MenuBar* CreateMenuBar();
#endif
  };
}