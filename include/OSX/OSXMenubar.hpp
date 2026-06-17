#ifdef __APPLE__
#pragma once
#include <ospch.hpp>
#include <OS/MenuBar.hpp>

namespace OSLib {
  class OSXMenuBar : public MenuBar {
  public:
    void Init() override;

    void AddMenu(OSLString _menuName) override;
    void AddSubMenu(OSLString _path, OSLString _subMenuName) override;
    void AddSepperator(OSLString _path) override;
    void AddItem(OSLString _path, OSLString _itemName, OSLString _key, std::function<void()> _callback) override;

    void SetItemDisabled(OSLString _path, OSLString _itemName, bool _disabled) override;
    void SetItemChecked(OSLString _path, OSLString _itemName, bool _checked) override;
  };
}
#endif