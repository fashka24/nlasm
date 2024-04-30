#pragma once

void run_asm(string ar) {
    string ld = "ld -o " + ar + " asm.o", run = "./"+ar;
    system(run.c_str());
    system("echo $?");
}
void build_asm(string ar) {
    string ld = "ld -o " + ar + " asm.o", run = "./"+ar;
    string gcc_s = "gcc asm.o -static -o " + ar;
    system("nasm -f elf64 asm.asm -o asm.o");
    if (!gcc) {
        system(ld.c_str()); // default ld
    }
    else {
        system(gcc_s.c_str()); // gcc ld
    }
    //    system(run.c_str());
}
void build_asm_with_delX(string ar) {
    string ld = "ld -o " + ar + " asm.o", run = "./"+ar;
    string gcc_s = "gcc asm.o -static -o " + ar;
    system("nasm -f elf64 asm.asm -o asm.o");
    system("rm asm.asm");
    if (!gcc) {
        system(ld.c_str()); // default ld
        system("rm asm.o");
    }
    else {
        system(gcc_s.c_str()); // gcc ld
        system("rm asm.o");
    }
    //    system(run.c_str());
}
void build_asm_with_del(string ar) {
    string ld = "ld -o " + ar + " asm.o", run = "./"+ar;
    string gcc_s = "gcc asm.o -static -o " + ar;
    system("nasm -f elf64 asm.asm -o asm.o");
    if (!gcc) {
        system(ld.c_str()); // default ld
        system("rm asm.o");
    }
    else {
        system(gcc_s.c_str()); // gcc ld
        system("rm asm.o");
    }
    //    system(run.c_str());
}