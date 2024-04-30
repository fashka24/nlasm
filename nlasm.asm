entr_p _start
#include "libs/stdlib.asm"
_start {
    ; creating variable test
    var test := "Hello" <- 10 ~
    ; output on console variable test
    out test <- 6
    ; exit in program
    retu 0
}