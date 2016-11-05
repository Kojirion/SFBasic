#include <boost/program_options.hpp>
#include "Interpreter.hpp"
#include <vector>
#include <iostream>
#include <functional>
#include <fstream>

int main(int ac, char* av[]){

    namespace po = boost::program_options;

    try {
        po::options_description desc("Allowed options");
        desc.add_options()
                ("help", "Display this information")
                ("version", "Display version information")
                ("text", po::value<std::string>(), "Text to interpret")
                ("file", po::value<std::string>(), "File to interpret")
                ;

        po::positional_options_description p;
        p.add("file", 1);

        po::variables_map vm;
        po::store(po::command_line_parser(ac, av).options(desc).positional(p).run(), vm);
        po::notify(vm);

        if (vm.count("help")) {
            std::cout << desc << std::endl;
            return 0;
        }

        if (vm.count("version")) {
            std::cout << "SFBasic 0.01" << std::endl
                      << "Copyright (C) 2016 Tina Winter\n"
                      << "License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.\n"
                      << "This is free software: you are free to change and redistribute it.\n"
                      << "There is NO WARRANTY, to the extent permitted by law." << std::endl;
            return 0;
        }


        Interpreter interpreter;

        if (vm.count("file")){
            auto filename = vm["file"].as<std::string>();
            std::ifstream file(filename);
            interpreter.interpret(file, false);
            return 0;
        }

        //if no arguments given, then interpret from stdin
        interpreter.interpret(std::cin, true);

    } catch(std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
