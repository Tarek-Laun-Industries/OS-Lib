#ifdef _WIN32
#pragma once
#include <ospch.hpp>
#include <OS/MenuBar.hpp>

namespace OSLib {
  class WINMenuBar : public MenuBar {
  public:
    WINMenuBar(HWND _window);

    void Init() override;

    void AddMenu(String _menuName) override;
    void AddSubMenu(String _path, String _subMenuName) override;
    void AddSepperator(String _path) override;
    void AddItem(String _path, String _itemName, String _key, std::function<void()> _callback) override;

    void SetItemDisabled(String _path, String _itemName, bool _disabled) override;
    void SetItemChecked(String _path, String _itemName, bool _checked) override;

    void RunCallbacks(uint32_t) override;

  private:
      std::vector<std::function<void()>> callBacks;
      HMENU menuBar;
      HWND hwnd;
      std::map<std::string, HMENU*> menus;
  };
}
#endif