#include <iostream> 
#include <fstream>
#include <sstream>
#include <ctime>

using namespace std;

int warnings = 0;
int errors = 0;

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
    unsigned int start_time =  clock(); // начальное время
    // здесь должен быть фрагмент кода, время выполнения которого нужно измерить
    build_asm(output_file);
    unsigned int end_time = clock(); // конечное время
    time_t t1 = time(NULL);
    tm t = *localtime(&t1);
    unsigned int search_time = end_time - start_time;
    cout << "Compilation " << termcolor::bright_green << "finished" << termcolor::reset << " at ";
    printf("%d.%d %.2d:%.2d:%.2d in %d milliseconds. ",t.tm_mon, t.tm_mday ,t.tm_hour, t.tm_min, t.tm_sec, search_time );
    cout << "With " << to_string(warnings) << " warnings and " << to_string(errors) << " errors." << endl;
    if (argr == "-R") {
        run_asm(output_file);
    }
    else if (argr == "-B") {
        cout << "Build " << termcolor::bright_green << "finished" << termcolor::reset << ".\n";
    }
    return 0; // retu 0 // send "Hello world~!!"
}