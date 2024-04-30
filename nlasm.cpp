#include <iostream> 
#include <fstream>
#include <sstream>
#include <ctime>
#include <unistd.h>

using namespace std;

bool gcc = false;
int warnings = 0;
int errors = 0;

#include "termcolor.hpp"
#include "src/tokenize.hpp"
#include "src/to_str.hpp"
#include "src/cppfile.hpp"
#include "src/errorlib.hpp"
#include "src/gem_asm.hpp"
#include "src/run_asm.hpp"

void clear() {
    system("clear");
}
#define s clear()


int main(int argc, char ** argv) {
    string argd = argv[1], argr = argv[2], output_file = argv[3];
    string code = rdfile(argd);
    vector<Token> tokens = lex(code);

//    preprocess preprocess;
//    preprocess.to_pre(tokens);
    to_asm(tokens, "asm.asm");

    unsigned int start_time =  clock(); // начальное время
    // здесь должен быть фрагмент кода, время выполнения которого нужно измерить
//    sleep(2);
    if (argr == "-BD") {
        build_asm_with_del(output_file);
    }
    else if (argr == "-BDa") {
        build_asm_with_delX(output_file);
    }
    else {
        build_asm(output_file);
    }unsigned int end_time = clock(); // конечное время
    time_t t1 = time(NULL);
    tm t = *localtime(&t1);
    unsigned int search_time = end_time - start_time;
    cout << "Compilation " << termcolor::bright_green << "finished" << termcolor::reset << " at ";
    printf("%d.%d %.2d:%.2d:%.2d in %d milliseconds. ",t.tm_mon+1, t.tm_mday ,t.tm_hour, t.tm_min, t.tm_sec, search_time );
    cout << "With " << to_string(warnings) << " warnings and " << to_string(errors) << " errors." << endl;
    if (argr == "-R") {
        run_asm(output_file);
    }
    else if (argr == "-B" || argr == "-BD" || argr == "-BDa") { // s
        cout << "Build " << termcolor::bright_green << "finished" << termcolor::reset << ".\n";
    }
    return 0; // retu 0 // send "Hello world~!!"
}