exit:             ; fun
   mov rax, 60
   mov rdi, 0
   syscall
   ret
exitc:             ; fun
   mov rax, 60
   syscall
   ret
sum:             ; fun
   push rdi
   mov rdi, 10
   mov rax, 5
   add rax, rdi
   pop rdi
   ret
