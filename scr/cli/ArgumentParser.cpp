//
// Created by Daniel Kahle on 21.02.2026.
//

#include "ArgumentParser.hpp"

#include <iostream>
#include <stdexcept>

#ifndef PROJECT_VERSION
#define PROJECT_VERSION "0.0.0"
#endif

namespace cli {

    Config ArgumentParser::parse(int argc, char* argv[]) {
        Config config;

        for (int i = 1; i < argc; ++i) {
            std::string arg = argv[i];

            if (arg == "--version" || arg == "-v") {
                config.showVersion = true;
            }
            else if (arg == "--help" || arg == "-h") {
                config.showHelp = true;
            }
            else if (!arg.empty() && arg[0] == '-') {
                throw std::invalid_argument("Unknown option: " + arg);
            }
            else {
                if (!config.inputFile.empty()) {
                    throw std::invalid_argument("Multiple input files specified");
                }
                config.inputFile = arg;
            }
        }

        return config;
    }

    void printVersion() {
        std::cout << "imgpipe " << PROJECT_VERSION << "\n";
    }

    void printHelp() {
        std::cout <<
            "Usage: imgpipe <input> [options]\n\n"
            "Options:\n"
            "  -v, --version        Show version\n"
            "  -h, --help           Show help\n";
    }

} // namespace cli
