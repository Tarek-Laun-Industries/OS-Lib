#ifdef _WIN32
#include <ospch.hpp>
#include "WIN/WINMenubar.hpp"

namespace OSLib {
	WINMenuBar::WINMenuBar(HWND _window) {
		hwnd = _window;
		callBacks = std::vector<std::function<void()>>();
		menus = std::map<std::string, HMENU*>();
	}

	void WINMenuBar::Init() {
		menuBar = CreateMenu();
	}

    void WINMenuBar::AddMenu(String _menuName) {
        menus[_menuName] = new HMENU();
        *menus[_menuName] = CreateMenu();
        AppendMenu(menuBar, MF_POPUP, (UINT_PTR)*menus[_menuName], _menuName.c_str());
        SetMenu(hwnd, menuBar);
    }

    void WINMenuBar::AddSubMenu(String _path, String _subMenuName) {
        std::vector<std::string> subMenues = Utils::SplitString(_path, '/');
        HMENU* _menu = &menuBar;
        if (!subMenues.back().empty()) {
            if (menus[subMenues.back()] != nullptr) {
                _menu = menus[subMenues.back()];
            }
        }

        menus[_subMenuName] = new HMENU();
        *menus[_subMenuName] = CreateMenu();
        AppendMenu(*_menu, MF_POPUP, (UINT_PTR)*menus[_subMenuName], _subMenuName.c_str());
        SetMenu(hwnd, menuBar);
    }

    void WINMenuBar::AddSepperator(String _path) {
        std::vector<std::string> subMenues = Utils::SplitString(_path, '/');
        HMENU* _menu = &menuBar;
        if (!subMenues.back().empty()) {
            if (menus[subMenues.back()] != nullptr) {
                _menu = menus[subMenues.back()];
            }
        }

        AppendMenu(*_menu, MF_SEPARATOR, 0, NULL);
        SetMenu(hwnd, menuBar);
    }

    void WINMenuBar::AddItem(String _path, String _itemName, String _key, std::function<void()> _callback) {
        std::vector<std::string> subMenues = Utils::SplitString(_path, '/');
        HMENU* _menu = &menuBar;
        if (!subMenues.back().empty()) {
            if (menus[subMenues.back()] != nullptr) {
                _menu = menus[subMenues.back()];
            }
        }

        callBacks.push_back(_callback);
        AppendMenu(*_menu, MF_STRING, callBacks.size() - 1, _itemName.c_str());
        SetMenu(hwnd, menuBar);
    }

    void WINMenuBar::SetItemDisabled(String _path, String _itemName, bool _disabled) {

    }

    void WINMenuBar::SetItemChecked(String _path, String _itemName, bool _checked) {

    }

    void WINMenuBar::RunCallbacks(uint32_t id) {
        if (callBacks.size() > id) {
            callBacks[id]();
        }
    }
}
#endif