# NLasm

### NLasm is new line asambler

- Have gooder output and syntax

## nlasm.asm :
    entr_p _start

    variables {
        message "Hello world", 10
    }
    _start {    
        out message, 12 ; send message
        retu 0
    }
## ouput :
    ┌──(fashka24㉿kali)-[nlasm]
    └─$ ./nlasm nlasm.asm nlasml
        Hello world