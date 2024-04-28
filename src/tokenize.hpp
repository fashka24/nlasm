#pragma once

#include <vector>

using namespace std;

enum tType {
    Number, String,
    Main, Id,
    Entr_p, Retu, Out, Goto, Move, Syscall, Add, Sub, RMulv, Mulv, Equals, Cmp, Run, Nr, R, Loop, NLoop, LoopNe,
    Outau,
    Include, Define, // preprocessor
    Nasm, // all nasm instructions 
    Colon, Comma, EqualsLiteral,
    RBrace, LBrace,
};

struct Token
{
    tType type;
    string value;
};

vector<Token> lex(string str){
	vector<Token> tokens;
	string out;
	for (int i = 0; i < str.length(); ++i) {
        if (str[i] == ';') {
            while (str[i] != '\n') {
                i++;
            }
        }
        else if (str[i] == '/') {
            i++;
            if (str[i] == '*') {
                i++;
                while (str[i] != '*' && str[i+1] != '/') {
                    i++;
                }
            }
        }
		else if (isalpha(str[i]) || str[i] == '_' || str[i] == '#') {
                        string buf;
                        while (isalnum(str[i]) || str[i] == '.' || str[i] == '_' || str[i] == '#') {
                                buf += str[i];
                                i++;
                        }
                        i -= 1;
                        if (buf == "entr_p")
                        {
                        tokens.push_back({tType::Entr_p, buf});
                        }
                        else if (buf == "retu")
                        {
                            tokens.push_back({tType::Retu, buf});
                        }
                        else if (buf == "nasm")
                        {
                            tokens.push_back({tType::Nasm, buf});
                        }
                        else if (buf == "#include")
                        {
                            tokens.push_back({tType::Include, buf});
                        }
                        else if (buf == "#define")
                        {
                            tokens.push_back({tType::Define, buf});
                        }
                        else if (buf == "run")
                        {
                            tokens.push_back({tType::Run, buf});
                        }
                        else if (buf == "nr")
                        {
                            tokens.push_back({tType::Nr, buf});
                        }
                        else if (buf == "mulv")
                        {
                            tokens.push_back({tType::Mulv, buf});
                        }
                        else if (buf == "rmulv")
                        {
                            tokens.push_back({tType::RMulv, buf});
                        }
                        else if (buf == "loop")
                        {
                            tokens.push_back({tType::Loop, buf});
                        }
                        else if (buf == "nloop")
                        {
                            tokens.push_back({tType::NLoop, buf});
                        }
                        else if (buf == "loopne")
                        {
                            tokens.push_back({tType::LoopNe, buf});
                        }
                        else if (buf == "r")
                        {
                            tokens.push_back({tType::R, buf});
                        }
                        else if (buf == "goto")
                        {
                            tokens.push_back({tType::Goto, buf});
                        }
                        else if (buf == "move")
                        {
                            tokens.push_back({tType::Move, buf});
                        }
                        else if (buf == "syscall")
                        {
                            tokens.push_back({tType::Syscall, buf});
                        }
                        else if (buf == "add")
                        {
                            tokens.push_back({tType::Add, buf});
                        }
                        else if (buf == "min")
                        {
                            tokens.push_back({tType::Sub, buf});
                        }
                        else if (buf == "cmp")
                        {
                            tokens.push_back({tType::Cmp, buf});
                        }
                        else if (buf == "equals")
                        {
                            tokens.push_back({tType::Equals, buf});
                        }
                        else if (buf == "out")
                        {
                            tokens.push_back({tType::Out, buf});
                        }
                        else if (buf == "outau") // auto length and auto add var
                        {
                            tokens.push_back({tType::Outau, buf});
                        }
                        else
                        {
                        tokens.push_back({tType::Id, buf});
                        }
                        
        }
        else if (isdigit(str[i])) {
                        string buf;
                        while (isalnum(str[i])) {
                                buf += str[i];
                                i++;
                        }
                        i -= 1;
                        tokens.push_back({tType::Number, buf});
        }
        else if (str[i] == '}') {
                        tokens.push_back({tType::LBrace, "}"});
                }
        else if (str[i] == '{') {
                        tokens.push_back({tType::RBrace, "{"});
                }
        else if (str[i] == ':') {
            tokens.push_back({tType::Colon, ":"});
                }
        else if (str[i] == ',') {
            tokens.push_back({tType::Comma, ","});
                }
        else if (str[i] == '<') {
            i++;
               if (str[i] == '-') {
                     tokens.push_back({tType::Comma, "<-"});
                }
               }
        else if (str[i] == '=') {
            tokens.push_back({tType::EqualsLiteral, "="});
                }
		else if (str[i] == '"') {
                        string buf;
				i++;
                        while (str[i] != '"') {
                                buf += str[i];
                                i++;
                        }
                        // i -= 1;
                        tokens.push_back({tType::String, buf});
                }
		else {
		continue;}


	}
	return tokens;
}

