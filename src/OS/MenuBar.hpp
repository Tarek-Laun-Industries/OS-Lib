#pragma once
#include <ospch.hpp>

namespace OSLib {
  class MenuBar {
  public:
    virtual void Init() {}

    virtual void AddMenu(String _menuName) {}
    virtual void AddSubMenu(String _path, String _subMenuName) {}
    virtual void AddSepperator(String _path) {}
    virtual void AddItem(String _path, String _itemName, String _key, std::function<void()> _callback) {}

    virtual void SetItemDisabled(String _path, String _itemName, bool _disabled) {}
    virtual void SetItemChecked(String _path, String _itemName, bool _checked) {}

    MenuBar* CreateMenuBar();
  };
}