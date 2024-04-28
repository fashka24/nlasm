; #include "stdlib.asm"

entr_p _start

_start {
    move rdi <- 60
    copy rdi <- rax     
    syscall
}