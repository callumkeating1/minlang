#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "lexer/lex.h"
int main(int argc, char* argv[]) {
    std::ifstream InputFile;
    std::string LineText;

    for (int i = 0; i < argc; ++i) {
        std::string arg = argv[i];  // convert to std::string
        if (arg == "-i" || arg == "--input") {
            if (i + 1 < argc) {
                std::string path = argv[i + 1];
                InputFile.open(path);
            } else {
                std::cerr << "Missing file path after " << arg << "\n";
            }
        }
    }
    if (!InputFile.is_open()) {
        std::cerr << "Error getting file, this could be caused because the "
                     "file is not specified or doesn't exist";
        return 1;
    }
    while (std::getline(InputFile, LineText)) {
        pair lexed = lex(LineText);
    }

    return 0;
}