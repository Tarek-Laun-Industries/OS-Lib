#ifdef __APPLE__
#pragma once
#include <ospch.hpp>
#include <OS/MenuBar.hpp>

namespace OSLib {
  class OSXMenuBar : public MenuBar {
  public:
    void Init() override;

    void AddMenu(String _menuName) override;
    void AddSubMenu(String _path, String _subMenuName) override;
    void AddSepperator(String _path) override;
    void AddItem(String _path, String _itemName, String _key, std::function<void()> _callback) override;

    void SetItemDisabled(String _path, String _itemName, bool _disabled) override;
    void SetItemChecked(String _path, String _itemName, bool _checked) override;
  };
}
#endif