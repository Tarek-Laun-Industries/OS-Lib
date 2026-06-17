#ifdef _WIN32
#pragma once
#include <ospch.hpp>
#include <OS/MenuBar.hpp>

namespace OSLib {
  class WINMenuBar : public MenuBar {
  public:
    WINMenuBar(HWND _window);

    void Init() override;

    void AddMenu(OSLString _menuName) override;
    void AddSubMenu(OSLString _path, OSLString _subMenuName) override;
    void AddSepperator(OSLString _path) override;
    void AddItem(OSLString _path, OSLString _itemName, OSLString _key, std::function<void()> _callback) override;

    void SetItemDisabled(OSLString _path, OSLString _itemName, bool _disabled) override;
    void SetItemChecked(OSLString _path, OSLString _itemName, bool _checked) override;

    void RunCallbacks(uint32_t) override;

  private:
      std::vector<std::function<void()>> callBacks;
      HMENU menuBar;
      HWND hwnd;
      std::map<std::string, HMENU*> menus;
      std::map<std::string, uint32_t*> ids;
  };
}
#endif