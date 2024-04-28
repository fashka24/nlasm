global _start            ; main FUNCTION -- _start
section .data
message: db "Hello apcahani", 10
section .text
_start:            ; FUNCTION
   mov rax, 60
   syscall
