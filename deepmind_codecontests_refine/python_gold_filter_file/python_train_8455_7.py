#!/usr/bin/env python3
import io, os
 
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
 
def get_str():
    return input().decode().strip()
 
def rint():
    return map(int, input().split())
 
def oint():
    return int(input())
 
t = oint()
 
for _ in range(t):
    n = oint()
    a = list(rint())
    p = [[] for __ in range(n+1)]
    for i in range(n):
        p[a[i]].append(i)
        if len(p[a[i]]) >= 2 and p[a[i]][-1] - p[a[i]][0] >= 2:
            print("YES")
            break
    else:
        print("NO")