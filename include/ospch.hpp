#pragma once

#include <string>
typedef std::string String;

#ifdef _WIN32
#include <windows.h>
#elif __linux__

#elif __APPLE__

#endif

// STD //
#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <filesystem>
#include <fstream>
#include <map>
#include <thread>
#include <functional>
#include <algorithm>
#include <random>