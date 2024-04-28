#include <iostream> 
#include <fstream>
#include <sstream>

using namespace std;

#include "termcolor.hpp"
#include "src/tokenize.hpp"
#include "src/to_str.hpp"
#include "src/gem_asm.hpp"
#include "src/run_asm.hpp"

void clear() {
    system("clear");
}
#define s clear()

string rdfile(string name_file){
    string output;
    ifstream file(name_file);
    {
        stringstream buf;
        if (file.is_open())
        {
            buf << file.rdbuf();
        }
        else {
            cout << "file not exist or is opened in another process" << endl;
            exit(1);
        }
        file.close();
        output = buf.str();
        buf.clear();
    }
    return output;
}

int main(int argc, char ** argv) {
    string argd = argv[1], argr = argv[2], output_file = argv[3];
    string code = rdfile(argd);
    vector<Token> tokens = lex(code);

    to_asm(tokens);
    if (argr == "-R") {
        run_asm(output_file);
    }
    else if (argr == "-B") {
        build_asm(output_file);
    }
    return 0; // retu 0 // send "Hello world~!!"
}