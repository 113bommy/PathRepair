#!/usr/bin/env python3
from sys import stdin,stdout


def ri():
    return map(int, input().split())

name1 = [ i for i in "ABCDEFGHIJKLMNOPQRSTUVWXYZ"]
name2= [ i for i in "abc"]
name = []
for i in range(3):
    for j in range(26):
        name.append(name1[j] + name2[i])

n, k = ri()
na = list(input().split(' '))
ans = [i for i in range(n)]

for i in range(0, n-k+1):
    if na[i] == "NO":
        ans[i+k-1] = ans[i]


print(" ".join([name[i] for i in ans]))



