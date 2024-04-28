exit {
    retu 0
} r
exitc {
    retu c
} r

sum {
    push rdi
    move rdi <- 10
    move rax <- 5
    add rax <- rdi
    pop rdi
} r