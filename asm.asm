global _start            ; main FUNCTION -- _start
section .data
__hello__: db "Hello!!!", 10
__hello__L: dq 9
section .text
exit:             ; fun
   mov rax, 60
   mov rdi, 0
   syscall
   ret
exitc:             ; fun
   mov rax, 60
   syscall
   ret

section .text
_start:            ; FUNCTION
   mov rax, 1
   mov rdi, 1
   mov rsi, __hello__
   mov rdx, [__hello__L]
   syscall
   mov rax, 60
   mov rdi, 0
   syscall
