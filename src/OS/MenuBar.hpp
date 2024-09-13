#pragma once
#include <pch.hpp>

namespace OSLib {
  class MenuBar {
  public:
    void Init();

    void AddMenu(String _menuName);
    void AddSubMenu(String _path, String _subMenuName);
    void AddSepperator(String _path);
    void AddItem(String _path, String _itemName, std::function<void()> _callback);

    void SetItemDisabled(String _path, String _itemName, bool _disabled);
    void SetItemChecked(String _path, String _itemName, bool _checked);
  };
}