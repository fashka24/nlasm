global _start            ; main FUNCTION -- _start
section .text
_start:            ; FUNCTION
   mov rax, 1
   mov rdi, 1
   mov rsi, message
   mov rdx, 12
   syscall
   mov rax, 60
   mov rdi, 0
   syscall
section .data
message: db "Hello world"

