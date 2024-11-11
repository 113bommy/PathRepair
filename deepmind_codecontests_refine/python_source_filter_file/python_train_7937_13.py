#!/usr/bin/env python3
import os
from sys import stdin, stdout


def solve(tc):
    n = int(stdin.readline().strip())
    seq = list(map(int, stdin.readline().split()))

    notok = []
    for i in range(n):
        if seq[i] != i+1:
            notok.append(i)

    if len(notok)==0:
        print(0)
    elif notok[-1]-notok[0]==len(notok)+1:
        print(1)
    else:
        print(2)


tcs = 1
tcs = int(stdin.readline().strip())
tc = 1
while tc <= tcs:
    solve(tc)
    tc += 1
