global _start            ; main FUNCTION -- _start
section .text
_start:            ; FUNCTION
   call exe
   mov rdi, 10
   mov rax, 60
   syscall
exe:             ; fun
   mov rax, 1
   mov rdi, 1
   mov rsi, sys0
   mov rdx, 3
   syscall
   mov rax, 1
   mov rdi, 1
   mov rsi, sys1
   mov rdx, 3
   syscall
   ret
section .data
sys0: db "45", 10
sys1: db "87", 10
