#include "lexmap.h"

#include <string>
#include <unordered_map>

#include "../lex.h"

std::unordered_map<std::string, keywords> keywordMap{
    {"print", keywords::PRINT},
    {"var", keywords::VAR},
    {"varadd", keywords::VARADD},
    {"set", keywords::VARSET},
};