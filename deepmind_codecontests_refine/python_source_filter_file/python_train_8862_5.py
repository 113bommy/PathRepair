#!/usr/bin/env python3
import sys

def rint():
    return map(int, sys.stdin.readline().split())
#lines = stdin.readlines()

n = int(input())

a = list(rint())

a.sort()

aa = [[a[0], 1]]
for i in range(1, n):
    if aa[-1][0] == a[i]:
        aa[-1][1] += 1
    else:
        aa.append([a[i], 1])


ans = 0
for i in range(len(aa)):
    cnt = aa[i][1]
    vs = aa[i][0]
    for j in range(i+1, i+5):
        if j >= len(aa):
            break
        v = aa[j][0]
        if v - vs <=  5:
            cnt += aa[j][1]

        else:
            break
    ans = max(ans, cnt)

print(ans)
