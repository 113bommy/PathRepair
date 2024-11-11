#!/usr/bin/env python3
from sys import stdin,stdout

def ri():
    return map(int, stdin.readline().split())
#lines = stdin.readlines()

n = int(input())
a = list(ri())

for i in range(n-1):
    a1, a2 = a[i], a[i+1]
    if (a1+a2)%2:
        if a2 == 0:
            print("NO")
            exit()
        else:
            a[i+1] = 1
    else:
        a[i+1] = 0

if a[n-1]:
    print("NO")
else:
    print("YES")
