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
        Hello world