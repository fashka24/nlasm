#pragma once

#include <vector>
#include <string>
#include <fstream>

#include "tokenize.hpp"

using namespace std;

void to_asm(vector<Token> tokens){
    fstream file2("asm.asm", ios_base::out);
    file2 << "";
    file2.close();
    fstream file("asm.asm", ios_base::app);
    file.clear();
    string main;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i].type == tType::Entr_p)
        {
            i++;
            if (tokens[i].type == tType::Id)
            {
                file << "global " + tokens[i].value + "            ; main FUNCTION -- " << tokens[i].value << endl;
                main = tokens[i].value;
            }
            continue;
        }
        if (tokens[i].type == tType::Id)
        {

            if (main == tokens[i].value)
            {
                file << "section .text" << endl;
                file << tokens[i].value;
                i++;
                if (tokens[i].type == tType::RBrace) {
                    file << ":            ; FUNCTION" << endl;
                    i++;
                    while (tokens[i].type != tType::LBrace) {
                        if (tokens[i].type == tType::Retu) {
                            i++;
                            file << "   mov rax, 60" << endl;
                            file << "   mov rdi, " + tokens[i].value << endl;
                            file << "   syscall" << endl;
                        }
                        else if (tokens[i].type == tType::Out) {
                            i++;
                            file << "   mov rax, 1" << endl;
                            file << "   mov rdi, 1" << endl;
                            file << "   mov rsi, " << tokens[i].value << endl;
                            i++;
                            if (tokens[i].type == tType::Comma) {
                                i++;
                                file << "   mov rdx, " << tokens[i].value << endl;
                            }
                            file << "   syscall" << endl;
                        }
                        i++;
                    }

                }
            }
            else if (tokens[i].value == "variables"){
                file << "section .data" << endl;
                i++;
                if (tokens[i].type == tType::RBrace) {
                    i++;
                    while (tokens[i].type != tType::LBrace) {
                        file << tokens[i].value << ": " << "db ";
                        i++;
                        file << "\"" << tokens[i].value << "\"";
                        i++;
                        if (tokens[i].type == tType::Comma) {
                            i++;
                            file << ", " << tokens[i].value << endl;
                        }
                        i++;
                    }

                }
            }
            



            continue;
        }
    }

}

