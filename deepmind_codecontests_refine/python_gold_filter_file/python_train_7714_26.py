#!/usr/bin/env python3
import sys

def rint():
    return map(int, sys.stdin.readline().split())
#lines = stdin.readlines()

l, r = rint()

print("YES")
for i in range((r-l+1)//2):
    print(l+2*i, l+2*i+1)
