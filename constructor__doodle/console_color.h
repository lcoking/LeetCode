#pragma once


//代替 windows.h 中的相关功能
//防止#include <windows.h>

constexpr auto RESET = "\033[0m";

constexpr auto BLACK = "\033[30m";

constexpr auto RED = "\033[31m";

constexpr auto GREEN = "\033[32m";

constexpr auto YELLOW = "\033[33m";

constexpr auto BLUE = "\033[34m";

constexpr auto MAGENTA = "\033[35m";

constexpr auto CYAN = "\033[36m";

constexpr auto WHITE = "\033[37m";

constexpr auto BOLDBLACK = "\033[1m\033[30m";

constexpr auto BOLDRED = "\033[1m\033[31m";

constexpr auto BOLDGREEN = "\033[1m\033[32m";

constexpr auto BOLDYELLOW = "\033[1m\033[33m";

constexpr auto BOLDBLUE = "\033[1m\033[34m";

constexpr auto BOLDMAGENTA = "\033[1m\033[35m";

constexpr auto BOLDCYAN = "\033[1m\033[36m";

constexpr auto BOLDWHITE = "\033[1m\033[37m";