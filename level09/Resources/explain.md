# level09 solution
Given setuid binary which is protected from tracing and wich we should not reverse. This program creates cipher from given string:

    ./level09 abcaaaa
    acedefg

The algorith is simple, it just adds index of the symbol in array to value with that index. If we write decipher program and give it provided ciphered token from file we will get token for flag09 user:

    f3iji1ju5yuevaus41q1afiuq
