global _start
.data
mess: db "Helldso world", 10
.text
_start:
    mov rax, 1          ; 1 - номер системного вызова функции write
    mov rdi, 1          ; 1 - дескриптор файла стандартного вызова stdout
    mov rsi, mess   ; адрес строки для вывод
    mov rdx, 12         ; количество байтов
    syscall             ; выполняем системный вызов write

    mov rax, 60         ; 60 - номер системного вызова exit
    syscall             ; выполняем системный вызов exi