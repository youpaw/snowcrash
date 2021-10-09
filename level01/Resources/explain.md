# level01 solution
There are no files in home directory and no files beloning to user flag01. But there are also not many places in linux which are available to current user and where password could be stored. Check the most obvious /etc/passwd.

    cat /etc/passwd | grep flag01
    flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash

User password hashes were stored in this file in earlier versions of Linux, but it was not safe. In modern versions it is stored in shadow file. I couln't find any rainbow tables for linux hashes (they are probably generated with salt), but the process of generation is standard so there is only one way to obtain this password - brute force. But it could take enormous computing power and very long time to calculate even a simple hash, so we should start with simple one first. There is a tool for system administrators called jhon reaper, this tool checks all simple passwords on provided hashes to find weak passwords.

    sudo apt install john //Install it
    john --show file/with/pass_cipher //Run on file with password hashes
    ?:abcdefg
    1 password hash cracked, 0 left

