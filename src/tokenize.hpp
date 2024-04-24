#pragma once

#include <vector>

using namespace std;

enum tType {
    Number, String,
    Main, Id,
    Entr_p, Retu, Out,
    Colon, Comma,
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
		else if (isalpha(str[i]) || str[i] == '_') {
                        string buf;
                        while (isalnum(str[i]) || str[i] == '.' || str[i] == '_' || str[i] == '/') {
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
                        else if (buf == "out")
                        {
                            tokens.push_back({tType::Out, buf});
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

