# OS Lib

**OS Lib** is a cross-platform C++ library developed by **Tarek Laun Industries**. It provides an easy-to-use API for accessing native operating system features such as menu bars, pop-ups, and opening URLs. This library simplifies the integration of native functionality without the complexity of platform-specific implementations.

## Features

- **Menu Bars**: Create and manage native menu bars.
- **Pop-ups**: Display native pop-up messages (e.g., info, warning, error).
- **URL Opening**: Open URLs in the user's default web browser.
- **Cross-platform**: Supports Windows, macOS, and Linux.

### Requirements

- C++17 or higher
- CMake 3.10 or higher

### Dependencies

- **Windows**: WinAPI
- **macOS**: Cocoa Framework

| Feature       | Windows | macOS | Linux |
|---------------|---------|-------|-------|
| Menu Bars     | ⚠️       | ✅    | ⚠️     |
| Pop-ups       | ⚠️       | ⚠️     | ⚠️     |
| URL Opening   | ✅       | ✅     | ⚠️     |

⚠️ = Not implemented yet!

© Tarek Laun Industries 2024