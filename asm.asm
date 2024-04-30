global _start            ; main FUNCTION -- _start
;      Code Include file {
section .data
__hello__: db "Hello!!!", 10
__hello__L: dq 9

section .text ;       Include nasm instruction
exit:             ; fun
   mov rax, 60
   mov rdi, 0
   syscall
   ret

exitc:             ; fun
   mov rax, 60
   syscall
   ret


;     } End Include File Code
section .text
_start:            ; FUNCTION
   mov rax, 1 ;      Output text in variable
   mov rdi, 1
   mov rsi, test
   mov rdx, 6
   syscall
   mov rax, 60 ;        Exit program instruction
   mov rdi, 0
   syscall
section .data
test: db "Hello", 10 ;       Output at inline vars

