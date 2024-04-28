#pragma once

#include <fstream>
#include <sstream>

#include "errorlib.hpp"

namespace cppfile {
    class file {
    private:
        std::fstream files;
    public:
        std::string read_filee(std::string name_file) {
            files.open(name_file, std::ios_base::in);
            std::string code;
            {
                std::stringstream buf;
                if (files.is_open()) {
                    buf << files.rdbuf();
                }
                else {
                    return "01";
                }
                files.close();
                code = buf.str();
            }
            return code;
        }
        std::string read_file(std::string name_file) {
            files.open(name_file, std::ios_base::in);
            std::string code;
            {
                std::stringstream buf;
                if (files.is_open()) {
                    buf << files.rdbuf();
                }
                else {
                    std::failwith("file not found", FAILWITH_RED);
                }
                files.close();
                code = buf.str();
            }
            return code;
        }
        void write_full_in_file(std::string name_file, std::string text) {
            files.open(name_file, std::ios_base::out);
            files << text;
        }
        void write_in_file(std::string name_file, std::string text) {
            files.open(name_file, std::ios_base::app);
            files << text;
        }
    };
}