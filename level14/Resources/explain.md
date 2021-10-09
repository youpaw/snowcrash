# level14 solution
There is nothing in home directory and no files belonging to level14 user or flag14 user, so the only source from which we can obtain token is getflag binary itself. We could dissasemble and reverse it, but because it contains all flags inside it we can simply copy it to another machine with root privelages and execute it under custom user with flag14 uid. To obtain flag14 uid we can simply look up /etc/passwd file:

    cat /etc/passwd | grep flag14
    flag14:x:3014:3014::/home/flag/flag14:/bin/bash

And after we execute getflag binary we would get:

    ./getflag 
    Check flag.Here is your token : 7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ

It is a token for flag14 user, after we login as one we would get:

    su flag14
    Password: 
    Congratulation. Type getflag to get the key and send it to me the owner of this livecd :)
    getflag
    Check flag.Here is your token : 7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ