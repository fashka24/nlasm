# NLasm

### NLasm is native lite assembler

- Have gooder output and syntax
- Dependencies: nlasm (compiler), nasm (not necessary: gcc)

### to start recomile all project :
    clang++/c++/g++ nlasm.cpp -o nlasm

## example/hello.asm :
    entr_p _start

    variables {
        message "Hello world", 10
    }
    _start {    
        out message, 12 ; send message
        retu 0
    }
## ouput :
    ┌──(fashka24㉿kali)-[/example]
    └─$ ./nlasm hello.asm -R hello
        Compilation finished at 3.28 13:40:08 in 244 milliseconds
        Hello world
## arguments variables :
    -R << build and run program
        example:
            ./nlasm hello.asm -R hello
            output:
                Compilation finished at 3.28 13:40:08 in 244 milliseconds
                Hello world (and files: asm.asm, asm.o, hello(executebale))

    -B << build program
        example:
            ./nlasm hello.asm -B hello
            output:
                Compilation finished at 3.28 13:40:08 in 244 milliseconds
                "files: asm.asm, asm.o, hello(executebale)"

    -BD << build program and delete file asm.o (build with delete)
        example:
            ./nlasm hello.asm -BD hello
            output:
                Compilation finished at 3.28 13:40:08 in 244 milliseconds
                "files: asm.asm, hello(executebale)"

    -BDa << build program and delete files asm.o, asm.asm (build with delete all) 
        example:
            ./nlasm hello.asm -BDa hello
            output:
                Compilation finished at 3.28 13:40:08 in 244 milliseconds
                "files: hello(executebale)"
