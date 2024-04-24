#pragma once

using namespace std;

void run_asm(string ar) {
    string ld = "ld -o " + ar + " asm.o", run = "./"+ar;
    system("nasm -f elf64 asm.asm -o asm.o");
    system(ld.c_str());
    system(run.c_str());
    system("echo $?");
}