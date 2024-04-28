exit:             ; fun
   mov rax, 60
   mov rdi, 0
   syscall
   ret
exitc:             ; fun
   mov rax, 60
   syscall
   ret
