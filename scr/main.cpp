//
// Created by Daniel Kahle on 21.02.2026.
//

#include "cli/ArgumentParser.hpp"

#include <iostream>
#include <stdexcept>

int main(int argc, char* argv[]) {
    try {
        // Show --help if no arguments given
        if (argc == 1) {
            cli::printHelp();
            return 0;
        }

        // Arguments parsing
        auto config = cli::ArgumentParser::parse(argc, argv);

        // --help
        if (config.showHelp) {
            cli::printHelp();
            return 0;
        }

        // --version
        if (config.showVersion) {
            cli::printVersion();
            return 0;
        }

        // input-file
        if (config.inputFile.empty()) {
            throw std::runtime_error(
                "Input file not specified. Use --help for usage.");
        }

        // Outputting the name of an input file (for now)
        std::cout << "Input file: " << config.inputFile << "\n";

        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
}