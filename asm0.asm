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
