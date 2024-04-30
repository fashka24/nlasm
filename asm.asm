global _start            ; main FUNCTION -- _start
section .text
_start:            ; FUNCTION
   mov rax, 1
   mov rdi, 1
   mov rsi, test
   mov rdx, 6
   syscall
   mov rax, 60
   mov rdi, 0
   syscall
section .text
test: db "Hello", 10

