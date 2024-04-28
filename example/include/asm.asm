global _start            ; main FUNCTION -- _start
section .data
message: db "Hello", 10
section .text
_start:            ; FUNCTION
   call outs
