global _start            ; main FUNCTION -- _start
exit:             ; fun
   mov rax, 60
   mov rdi, 0
   syscall
   ret
exitc:             ; fun
   mov rax, 60
   syscall
   ret

_start:
    mov rax, 60
    mov rdi, 0
    syscall
