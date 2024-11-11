#!/usr/bin/env python3

n, m, k = [int(x) for x in input().split()]

row = [(0, -1)] * n
col = [(0, -1)] * m
for i in range(0, k):
    t, num, color = [int(x) for x in input().split()]
    num -= 1
    if t == 1:
        row[num] = (color, i)
    else:
        assert t == 2
        col[num] = (color, i)

for r in row:
    for c in col:
        if c[1] > r[1]:
            print(c[0], end=' ')
        else:
            print(r[0], end=' ')
    print()

