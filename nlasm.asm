entr_p _start
_start {
   run exe
   move rdi, 10
   retu c
}
exe {
    out sys0, 3
    out sys1, 3
} nr
variables {
sys0 "45", 10
sys1 "87", 10
}
