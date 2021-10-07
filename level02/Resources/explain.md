# level02 solution
There is a .pcap file in home directory which is a recording of some traffic. We can download via scp on host machine and take a closer look on it using wireshark. Wireshark is a popular GUI traffic capturing and analyzing tool. This recording contains client server http traffic. If we search for packets wich contain "password" string in frame, we can find packet with lgoin form. Then we can follow tcp stream and view joined data payload from tcp packets:


    Password: ft_wandr...NDRel.L0L

Seems like some symbols are not printable, we can convert it to hex view to see what are those symbols:

    6c 65 76 65 6c 58 0d 66 74 5f 77 61 6e 64 72 7f 7f 7f 4e 44 52 65 6c 7f 4c 30 4c 0d

7f symbol refers to del key, so remove it and matching number of symbols behind it:

    6c 65 76 65 6c 58 0d 66 74 5f 77 61 4e 44 52 65 4c 30 4c 0d

Now we convert it back to ascii and get our token:

    ft_waNDReL0L
