//
// Created by Daniel Kahle on 21.02.2026.
//

#pragma once

#include <string>

namespace cli {

    struct Config {
        bool showVersion = false;
        bool showHelp = false;
        std::string inputFile;
    };

    class ArgumentParser {
    public:
        static Config parse(int argc, char* argv[]);
    };

    void printVersion();
    void printHelp();

} // namespace cli
