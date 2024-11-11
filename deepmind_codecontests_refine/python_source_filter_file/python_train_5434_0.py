#!/usr/bin/env python3
import sys

#lines = stdin.readlines()
def rint():
    return map(int, sys.stdin.readline().split())

def input():
    return sys.stdin.readline().rstrip('\n')

def oint():
    return int(input())


n = oint()
stemp  = input()
s = []
for i in range(n):
    if stemp[i] == '(':
        s.append(1)
    else:
        s.append(-1)

maxcnt = 0
candi = [0, 0]
for l in range(n):
    for r in range(l, n):
        cnt = 0
        s[l], s[r] = s[r], s[l]
        ssum = [0]*n
        ssum[0] = s[0]
        for i in range(1, n):
            ssum[i] = ssum[i-1] + s[i]

        minssum = min(ssum)
        if ssum[n-1] != 0:
            continue

        for i in range(1, n):
            if ssum[i] == minssum:
                cnt += 1
        if maxcnt < cnt:
            candi = [r, l]
            maxcnt = cnt
        s[l], s[r] = s[r], s[l]
print(maxcnt)
print(candi[0]+1, candi[1]+1)
