#!/usr/bin/env python3
from sys import stdin, stdout

def rint():
    return map(int, stdin.readline().split())
#lines = stdin.readlines()


n = int(input())

a = list(rint())

a.sort()

Min = 10**1000

for i in range(1,n-1):
    Min = min(Min, (a[n+i] - a[i]) * (a[n*2-1] - a[0]) )

Min = min(Min, (a[n-1] - a[0]) * (a[2*n-1] - a[n]) )

print(Min)

