#include <boost/program_options.hpp>
#include "Grammars.hpp"
#include <map>
#include <vector>
#include <iostream>
#include <functional>
#include <fstream>

struct Interpreter
{
    void Print(char a){std::cout << variables[a] << '\n';}

    void Input(char a){
        std::cin >> variables[a];
        std::cin.ignore(); //TOFIX: Yet this is unecessary and even wrong if interpreting from file
    }

    void Add(std::vector<char> results){
        variables[results[0]] = variables[results[1]] + variables[results[2]];
    }

    std::map<char, int> variables;
};

//TODO: a quit grammar

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

        PrintGrammar printGrammar;
        InputGrammar inputGrammar;
        AdditionGrammar additionGrammar;

        Interpreter interpreter;

        if (vm.count("file")){
            auto filename = vm["file"].as<std::string>();
            std::cout << "Interpreting " << filename << std::endl; //TODO: make this optional with a verbose flag
            std::ifstream file(filename);
            //TODO: interpret stream instead of line by line
            int lineCount = 1;
            for (std::string line; std::getline(file, line);){
                std::cout << lineCount++ << ": " << line << std::endl;
                auto it = line.begin();
                using std::placeholders::_1;
                auto r = parse(it, line.end(), inputGrammar[std::bind(&Interpreter::Input, &interpreter, _1)] |
                                               printGrammar[std::bind(&Interpreter::Print, &interpreter, _1)] |
                                               additionGrammar[std::bind(&Interpreter::Add, &interpreter, _1)]);
                if (!r){
                    std::cout << "Error at \n" << std::string(it, line.end()) << std::endl;
                }
            }
            std::cout << "End of interpratation\n";
            return 0;
        }

        bool running(true);

        std::string line;
        using boost::spirit::qi::parse;

        while(running){
            std::cout << "basic> " << std::flush;
            std::getline(std::cin, line);
            auto it = line.begin();
            using std::placeholders::_1;
            auto r = parse(it, line.end(), inputGrammar[std::bind(&Interpreter::Input, &interpreter, _1)] |
                                           printGrammar[std::bind(&Interpreter::Print, &interpreter, _1)] |
                                           additionGrammar[std::bind(&Interpreter::Add, &interpreter, _1)]);
            if (!r){
                std::cout << "Error at \n" << std::string(it, line.end()) << std::endl;
            }
        }
    } catch(std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }



}
