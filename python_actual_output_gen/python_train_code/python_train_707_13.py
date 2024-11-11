#!/usr/bin/env python3
# -*- coding: utf-8 -*-

#import time
ans={True:"YES", False:"NO"}

s       = input()
flag    = False
p       = s.find("AB")

if "AB" in s and "BA" not in s:
    while(p != -1) :

        s   = s[:p]         + 'ab'+s[p+2:]
        buf = s[:p].upper() + 'ab'+s[p+2:]

        if "BA" in buf:
            flag = True
            break

        p = s.find("AB")

print(ans[flag])
#start = time.time()
#finish = time.time()
#print(finish - start)



