#!/usr/bin/env python3
import sys

def rint():
    return map(int, sys.stdin.readline().split())
#lines = stdin.readlines()

l, r = rint()

print("YES")
for i in range((r-l+1)//2):
    print(l+i, l+i+1)
