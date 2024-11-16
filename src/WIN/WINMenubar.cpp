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
        HMENU* _menu = &menuBar;
        if (menus[_path] != nullptr) {
            _menu = menus[_path];
        }

        String _newName = _path + "/" + _subMenuName;

        menus[_newName] = new HMENU();
        *menus[_newName] = CreateMenu();
        AppendMenu(*_menu, MF_POPUP, (UINT_PTR)*menus[_newName], _subMenuName.c_str());
        SetMenu(hwnd, menuBar);
    }

    void WINMenuBar::AddSepperator(String _path) {
        HMENU* _menu = &menuBar;
        if (menus[_path] != nullptr) {
            _menu = menus[_path];
        }

        AppendMenu(*_menu, MF_SEPARATOR, 0, NULL);
        SetMenu(hwnd, menuBar);
    }

    void WINMenuBar::AddItem(String _path, String _itemName, String _key, std::function<void()> _callback) {
        HMENU* _menu = &menuBar;
        if (menus[_path] != nullptr) {
            _menu = menus[_path];
        }

        String _itemPath = _path + "/" + _itemName;

        callBacks.push_back(_callback);
        AppendMenu(*_menu, MF_STRING, callBacks.size() - 1, _itemName.c_str());
        ids[_itemPath] = new uint32_t();
        *ids[_itemPath] = callBacks.size() - 1;
        SetMenu(hwnd, menuBar);
    }

    void WINMenuBar::SetItemDisabled(String _path, String _itemName, bool _disabled) {
        HMENU* _menu = &menuBar;
        uint32_t id = 0;
        if (menus[_path] != nullptr) {
            _menu = menus[_path];
        }
        String _itemPath = _path + "/" + _itemName;
        id = *ids[_itemPath];


        if (_disabled) {
            EnableMenuItem(*_menu, id, MF_BYCOMMAND | MF_DISABLED);
        }
        else {
            EnableMenuItem(*_menu, id, MF_BYCOMMAND | MF_ENABLED);
        }
    }

    void WINMenuBar::SetItemChecked(String _path, String _itemName, bool _checked) {
        HMENU* _menu = &menuBar;
        uint32_t id = 0;
        if (menus[_path] != nullptr) {
            _menu = menus[_path];
        }
        String _itemPath = _path + "/" + _itemName;
        id = *ids[_itemPath];


        if (_checked) {
            CheckMenuItem(*_menu, id, MF_BYCOMMAND | MF_CHECKED);
        }
        else {
            CheckMenuItem(*_menu, id, MF_BYCOMMAND | MF_UNCHECKED);
        }
    }

    void WINMenuBar::RunCallbacks(uint32_t id) {
        if (callBacks.size() > id) {
            callBacks[id]();
        }
    }
}
#endif