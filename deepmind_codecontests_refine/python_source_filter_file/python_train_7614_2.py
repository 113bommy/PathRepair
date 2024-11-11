#!/usr/bin/env python3
import sys

def rint():
    return map(int, sys.stdin.readline().split())
#lines = stdin.readlines()


n, m, h = rint()

fv = list(rint())
lv = list(rint())

tv = [[] for i in range(n)]

#print(fv)
#print(lv)
for i in range(n):
    tv[i] = list(rint())
#    print(tv[i])

for i in range(n):
    for j in range(m):
        if tv[i][j] == 0:
            continue
        tv[i][j] = fv[j]

for c in range(m):
    for r in range(n):
        if tv[r][c] > lv[r]:
            tv[r][c] = lv[r]


for i in range(n):
    print(tv[i])
