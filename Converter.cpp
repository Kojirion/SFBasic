#include <boost/program_options.hpp>
#include "Grammars.hpp"
#include <map>
#include <vector>
#include <iostream>
#include <functional>

struct Converter
{
    Converter(std::ostream& os):
    output(os)
    {
        output << "#include <iostream>\n"
               << "#include <map>\n\n"
               << "int main(){\n"
               << "std::map<char, int> variables;\n";
    }

    void Print(char a){
        output << "std::cout << variables[" << a <<"] << std::endl;";
    }

    void Input(char a){
        output << "std::cin >> variables[" << a << "];";
    }

    void Add(std::vector<char> results){
        output << "variables[" << results[0] << "] = variables[" << results[1]
               << "] + variables[" << results[2] << "];";
    }

    std::ostream& output;
};


int main(int ac, char* av[]){

    namespace po = boost::program_options;

    try {
        po::options_description desc("Allowed options");
        desc.add_options()
                ("help", "Display this information")
                ("version", "Display version information")
                ("text", po::value<std::string>(), "Text to convert")
                ("file", po::value<std::string>(), "File to convert")
                ;

        po::positional_options_description p;

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
    } catch(std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    PrintGrammar printGrammar;
    InputGrammar inputGrammar;
    AdditionGrammar additionGrammar;

    Converter converter(std::cout);

    bool running(true);

    std::string line;
    using boost::spirit::qi::parse;

//    while(running){
//        std::cout << "basic> " << std::flush;
//        std::getline(std::cin, line);
//        auto it = line.begin();
//        using std::placeholders::_1;
//        auto r = parse(it, line.end(), inputGrammar[std::bind(&Interpreter::Input, &interpreter, _1)]);
//        if (!r){
//            std::cout << "Error at \n" << std::string(it, line.end()) << std::endl;
//        }
//    }
}