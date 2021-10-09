# level13 solution
Given setuid elf binary, run it to see what it does:
    
    ./level13 
    UID 2013 started us but we we expect 4242

This binary is meant to be run by user with 4242 uid, we can not bypass this check inside snowcrash machine. Let's see what it does whith gdb:

    gdb ./level13 
    (gdb) set disassembly-flavor intel
    (gdb) disass *main
    Dump of assembler code for function main:
    0x0804858c <+0>:	push   ebp
    0x0804858d <+1>:	mov    ebp,esp
    0x0804858f <+3>:	and    esp,0xfffffff0
    0x08048592 <+6>:	sub    esp,0x10
    0x08048595 <+9>:	call   0x8048380 <getuid@plt>
    0x0804859a <+14>:	cmp    eax,0x1092
    0x0804859f <+19>:	je     0x80485cb <main+63>
    0x080485a1 <+21>:	call   0x8048380 <getuid@plt>
    0x080485a6 <+26>:	mov    edx,0x80486c8
    0x080485ab <+31>:	mov    DWORD PTR [esp+0x8],0x1092
    0x080485b3 <+39>:	mov    DWORD PTR [esp+0x4],eax
    0x080485b7 <+43>:	mov    DWORD PTR [esp],edx
    0x080485ba <+46>:	call   0x8048360 <printf@plt>
    0x080485bf <+51>:	mov    DWORD PTR [esp],0x1
    0x080485c6 <+58>:	call   0x80483a0 <exit@plt>
    0x080485cb <+63>:	mov    DWORD PTR [esp],0x80486ef
    0x080485d2 <+70>:	call   0x8048474 <ft_des>
    0x080485d7 <+75>:	mov    edx,0x8048709
    0x080485dc <+80>:	mov    DWORD PTR [esp+0x4],eax
    0x080485e0 <+84>:	mov    DWORD PTR [esp],edx
    0x080485e3 <+87>:	call   0x8048360 <printf@plt>
    0x080485e8 <+92>:	leave 

It seems to get some hardcoded string, apply on it ft_des function and output token with printf. So this binary does not have to be run on snowcrash system and since we have read and execute permissions on this binary we can simply scp this binary on some other system where we do have root permissions, create user with uid=4242 and run this binary under created user, then we would get:

    ./level13 
    your token is 2A31L79asukciNyi8uppkEuSx