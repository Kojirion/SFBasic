#include <boost/program_options.hpp>
#include "../Grammars/Input.hpp"
#include "../Grammars/Print.hpp"
#include "../Grammars/Expression.hpp"
#include <map>
#include <vector>
#include <iostream>
#include <functional>
#include <fstream>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>

struct Formatter
{
    Formatter(std::ostream& os):
    output(os)
    {

    }

    void Print(Variable v){
        output << "PRINT " << v << "\n";
    }

    void Input(Variable v){
        output << "INPUT " << v << "\n";
    }

    void Add(std::vector<Variable> v){
        output << v[0] << " = " << v[1] << " + " << v[2] << "\n";
    }

    void formatLine(std::string& line){
        auto it = line.begin();
        using std::placeholders::_1;
        auto r = qi::parse(it, line.end(),
                              inputGrammar[std::bind(&Formatter::Input, this, _1)] |
                              printGrammar[std::bind(&Formatter::Print, this, _1)] |
                              additionGrammar[std::bind(&Formatter::Add, this, _1)]);

        if (!r){
            std::cout << "Error at \n" << std::string(it, line.end()) << std::endl;
        }
    }

    Grammars::Print printGrammar;
    Grammars::Input inputGrammar;
    Grammars::Addition additionGrammar;

    std::ostream& output;
};

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


        Formatter formatter(std::cout);

        if (vm.count("file")){
            auto filename = vm["file"].as<std::string>();
            std::ifstream file(filename);
            for (std::string line; std::getline(file, line);){
                std::cout << line << '\n';
                formatter.formatLine(line);
            }
            return 0;
        }

    } catch(std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
