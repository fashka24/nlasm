entr_p _start

variables {
    message "Hello world", 10
}
_start {
    out message, 12 ; send message
    retu 22
}