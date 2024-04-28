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

section .text
_start:            ; FUNCTION
   mov rdi, 22
   call exitc
