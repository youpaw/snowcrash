# level00 solution
There is nothing in the home directory, try to find all files beloning to user flag00 and filter all error
    find / -user flag00 -group flag00 2>/dev/null
    /usr/sbin/john
Found one file, check its contence
    cat /usr/sbin/john
    cdiiddwpgswtgt
This token seems to be ciphered. Used cipher algorthim most likely to be simple because it is only the first level. The are no digits in this cipher, so it is probably Ceaser cipher. Try to decipher Rot13 with different parameters using online sevice. After applying decipher for Rot11 readable text appeared:
    nottoohardhere