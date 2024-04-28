#pragma once

#include <vector>
#include <string>
#include <fstream>

#include "tokenize.hpp"

using namespace std;
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

void to_asm(vector<Token> tokens, string na_s){
    fstream file2(na_s, ios_base::out);
    file2 << "";
    file2.close();
    fstream file(na_s, ios_base::app);
    file.clear();
    int y = 0;
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
        if (tokens[i].type == tType::Include)
        {
            i++;
            string o = tokens[i].value;
            cout << o << endl;
            string nc_code = rdfile(o);
            auto toks = lex(nc_code);
            to_asm(toks, "asm" + to_string(y) + ".asm");
            string na_code = rdfile("asm" + to_string(y) + ".asm");
            y++;
            file << na_code << endl;
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
                            if (tokens[i].type == tType::Number) {
                                file << "   mov rdi, " + tokens[i].value << endl;
                            } else if (tokens[i].type == tType::Id && tokens[i].value == "c") {
                            }
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
                        else if (tokens[i].type == tType::Cmp) {
                            i++;
                            file << "   cmp "<< tokens[i].value;
                            i++;
                            if (tokens[i].type == tType::Comma) {
                                i++;
                                file << ", " << tokens[i].value << endl;
                            }
                        }
                        else if (tokens[i].type == tType::Equals) {
                            i++;
                            file << "   je "<< tokens[i].value << endl;
                        }
                        else if (tokens[i].type == tType::Run) {
                            i++;
                            file << "   call "<< tokens[i].value << endl;
                        }
                        else if (tokens[i].type == tType::Goto) {
                            i++;
                            file << "   jmp " << tokens[i].value << endl;
                        }
                        else if (tokens[i].type == tType::RMulv) {
                            i++;
                            file << "   mul " << tokens[i].value << endl;
                        }
                        else if (tokens[i].type == tType::Add) {
                            i++;
                            file << "   add " << tokens[i].value;
                            i++;
                            if (tokens[i].type == tType::Comma) {
                                i++;
                                file << ", ";
                                file << tokens[i].value << endl;
                            }
                        }
                        else if (tokens[i].type == tType::Sub) {
                            i++;
                            file << "   sub " << tokens[i].value;
                            i++;
                            if (tokens[i].type == tType::Comma) {
                                i++;
                                file << ", ";
                                file << tokens[i].value << endl;
                            }
                        }
                        else if (tokens[i].type == tType::Mulv) {
                            i++;
                            file << "   imul " << tokens[i].value;
                            i++;
                            if (tokens[i].type == tType::Comma) {
                                i++;
                                file << ", ";
                                file << tokens[i].value;
                                i++;
                                if (tokens[i].type == tType::Comma) {
                                    i++;
                                    file << ", ";
                                    file << tokens[i].value << endl;
                                }
                                else {
                                    file << endl;
                                    i--;
                                }
                            }
                            else {
                                cout << termcolor::bright_red << "Error" << termcolor::reset << ": not used mulv instruction." << endl;
                                errors++;
                            }
                        }
                        else if (tokens[i].type == tType::Move) {
                            i++;
                            file << "   mov " << tokens[i].value;
                            i++;
                            if (tokens[i].type == tType::Comma) {
                                file << ", ";
                                i++;
                                if (tokens[i].type == tType::Id || tokens[i].type == tType::Number) {
                                    file << tokens[i].value << endl;
                                }
                                else {
                                    cout << "not close comma tag" << endl;
                                    exit(1);
                                }
                            }
                            else {
                                i--;
                                cout << "not implemented tag << " << tokens[i].value << endl;
                                exit(1);
                            }
                        }
                        else if (tokens[i].type == tType::Syscall) {
                            file << "   syscall"<<endl;
                        }
                        else if (tokens[i].type == tType::Loop) {
                            i++;
                            file << "   loop ";
                            file << tokens[i].value << endl;
                        }
                        else if (tokens[i].type == tType::NLoop) {
                            i++;
                            file << "   jrcxz ";
                            file << tokens[i].value << endl;
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
                        if (tokens[i].type == tType::String) {
                            file << "\"" << tokens[i].value << "\"";
                            i++;
                            if (tokens[i].type == tType::Comma) {
                                i++;
                                file << ", " << tokens[i].value << endl;i++;
                            } else {
                                file << endl;
                            }
                        }
                        else if (tokens[i].type == tType::Number) {
                            file << tokens[i].value << endl;
                            i++;
                        }
                    }

                }
            }
            else {
                file << tokens[i].value;
                i++;
                if (tokens[i].type == tType::RBrace) {
                    file << ":             ; fun" << endl;
                    i++;
                    while (tokens[i].type != tType::LBrace) {
                        if (tokens[i].type == tType::Retu) {
                            i++;
                            file << "   mov rax, 60" << endl;
                            if (tokens[i].type == tType::Number) {
                                file << "   mov rdi, " + tokens[i].value << endl;
                            } else if (tokens[i].type == tType::Id && tokens[i].value == "c") {
                            }
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
                        else if (tokens[i].type == tType::Cmp) {
                            i++;
                            file << "   cmp "<< tokens[i].value;
                            i++;
                            if (tokens[i].type == tType::Comma) {
                                i++;
                                file << ", " << tokens[i].value << endl;
                            }
                        }
                        else if (tokens[i].type == tType::Equals) {
                            i++;
                            file << "   je "<< tokens[i].value << endl;
                        }
                        else if (tokens[i].type == tType::Goto) {
                            i++;
                            file << "   jmp " << tokens[i].value << endl;
                        }
                        else if (tokens[i].type == tType::RMulv) {
                            i++;
                            file << "   mul " << tokens[i].value << endl;
                        }
                        else if (tokens[i].type == tType::Add) {
                            i++;
                            file << "   add " << tokens[i].value;
                            i++;
                            if (tokens[i].type == tType::Comma) {
                                i++;
                                file << ", ";
                                file << tokens[i].value << endl;
                            }
                        }
                        else if (tokens[i].type == tType::Sub) {
                            i++;
                            file << "   sub " << tokens[i].value;
                            i++;
                            if (tokens[i].type == tType::Comma) {
                                i++;
                                file << ", ";
                                file << tokens[i].value << endl;
                            }
                        }
                        else if (tokens[i].type == tType::Mulv) {
                            i++;
                            file << "   imul " << tokens[i].value;
                            i++;
                            if (tokens[i].type == tType::Comma) {
                                i++;
                                file << ", ";
                                file << tokens[i].value;
                                i++;
                                if (tokens[i].type == tType::Comma) {
                                    i++;
                                    file << ", ";
                                    file << tokens[i].value << endl;
                                }
                                else {
                                    file << endl;
                                    i--;
                                }
                            }
                            else {
                                cout << termcolor::bright_red << "Error" << termcolor::reset << ": not used mulv instruction." << endl;
                                errors++;
                            }
                        }
                        else if (tokens[i].type == tType::Move) {
                            i++;
                            file << "   mov " << tokens[i].value;
                            i++;
                            if (tokens[i].type == tType::Comma) {
                                file << ", ";
                                i++;
                                if (tokens[i].type == tType::Id || tokens[i].type == tType::Number) {
                                    file << tokens[i].value << endl;
                                }
                                else {
                                    cout << "not close comma tag" << endl;
                                    exit(1);
                                }
                            }
                            else {
                                i--;
                                cout << "not implemented tag << " << tokens[i].value << endl;
                                exit(1);
                            }
                        }
                        else if (tokens[i].type == tType::Syscall) {
                            file << "   syscall"<<endl;
                        }
                        else if (tokens[i].type == tType::Loop) {
                            i++;
                            file << "   loop ";
                            file << tokens[i].value << endl;
                        }
                        else if (tokens[i].type == tType::NLoop) {
                            i++;
                            file << "   jrcxz ";
                            file << tokens[i].value << endl;
                        }
                        i++;
                    }
                    if (i + 1 != tokens.size()) {
                        i++;
                        if ((tokens[i].type != tType::Nr && tokens[i].value != "nr") || (tokens[i].type == tType::R && tokens[i].value == "r")) {
                            file << "   ret" << endl;
                        }
                        else {
                            cout << termcolor::bright_yellow << "Warning" << termcolor::reset << ": not return to main function." << endl;
                            warnings++;
                        }
                        i--;
                    }
                }
            }
            



            continue;
        }
    }

}

