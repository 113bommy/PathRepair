#include <bits/stdc++.h>
#define STD /*
from sys import (
stdin, stdout, exit as sys_ret)
"""****************************

       Interactive Tasks:

          / Python: /       """
f_input, f_print, f_flush = (
        stdin.readline,
        stdout.write,
        stdout.flush)

"""        / C++ /
       #import <cstdio>
       fflush(stdout);
             or
       #import <iostream>
       cout << endl;

   —————————————————————————
    Don't raise your voice,
    improve your argument.
   —————————————————————————

   cat /dev/ass > /dev/head
            Ctrl+C
   cat /knowledge > /dev/head

                © Jakov Gellert
                        frvr.ru

****************************"""
# */ using namespace std; int

for _ in range(int(f_input())):
    length, string = int(f_input()), f_input()
    if '8' not in string:
        f_print("NO\n")
        continue
    if length - string.find('8') >= 8:
        f_print("YES\n")
    else:
        f_print("NO\n")