#pragma once
#include <string>

enum class keywords {
    PRINT,
    VAR,
    VARADD,
    VARSET,
    UNKNOWN,
};

struct pair {
    keywords keyword;
    std::string value;
};

pair lex(std::string line);