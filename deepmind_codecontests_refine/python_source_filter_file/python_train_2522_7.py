#!/usr/bin/env python3
import io, os
from sys import setrecursionlimit
from collections import defaultdict
from itertools import groupby

input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

def rint():
    return map(int, input().split())

def oint():
    return int(input())

def get_str():
    return input().decode()[:-1:]

n, m, k = rint()
fla= [len(a) for a in get_str().replace(' ', '').split('0') if len(a)]
flb= [len(a) for a in get_str().replace(' ', '').split('0') if len(a)]

ans = 0
i = 1
while i*i <= k:
    if k%i == 0:
        sr = i
        sc = k//sr
        ans += sum(r-sr+1 for r in fla if sr <= r) * sum(c-sc+1 for c in flb if sc <= c)
        if sr == sc:
            break
        sr, sc = sc, sr
        ans += sum(r-sr+1 for r in fla if sr <= r) * sum(c-sc+1 for c in flb if sc <= c)
    i += 1
print(ans)
