#include "lex.h"

#include <iostream>
#include <vector>

#include "map/lexmap.h"

// print {value}
// var ${variable}
// varadd name value
// varset ${name} value

struct pair {
    keywords keyword;
    std::string value;
};

keywords convertToKeyword(std::string word) {
    auto it = keywordMap.find(word);
    if (it != keywordMap.end()) {
        return it->second;  // found keyword
    }
    return keywords::UNKNOWN;
}

pair lex(std::string line) {
    std::vector<std::string> words;
    pair linePair;
    std::string word;
    int loopnum = 0;
    for (char c : line) {
        loopnum++;
        if (c != ' ' and loopnum != line.length()) {
            word += c;
        } else {
            if (loopnum == line.length()) {
                word += c;
            }
            words.push_back(word);
            std::cout << word << "\n";
            word.clear();
        };
    }
    for (size_t i = 0; i < words.size(); ++i) {
        if (i == 0) {
            linePair.keyword = convertToKeyword(words.at(i));
        } else {
            linePair.value += words.at(i);
        }
    }
    return linePair;
}

int main() {
    pair user = lex("PRINT hello");
    return 0;
}