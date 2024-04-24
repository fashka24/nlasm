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
    s;
    string argd = argv[1], argr = argv[2];
    string code = rdfile(argd);
    vector<Token> tokens = lex(code);

    to_asm(tokens);
    run_asm(argr);
    return 0; // retu 0 // send "Hello world~!!"
}