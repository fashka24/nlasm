# NLasm

### NLasm is new line asambler

- Have gooder output and syntax

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
