#!/usr/bin/python3

n = int(input())
a = tuple(map(int, input().split()))

ms = [ [0 for i in range(3)] for j in range(n) ]

ms[0][0] = 0
ms[0][1] = 0
ms[0][2] = a[0]

ms[1][0] = 0
ms[1][1] = max(a[0], a[1])

for i in range(2, n):
    if i % 2 == 1:
        ms[i][0] = max(ms[i - 1][1], ms[i - 2][0] + a[i])
        ms[i][1] = max(ms[i - 1][2], ms[i - 2][1] + a[i])
    else:
        ms[i][0] = ms[i - 1][0]
        ms[i][1] = max(ms[i - 1][1], ms[i - 2][1] + a[i])
        ms[i][2] = ms[i - 2][2] + a[i]


print(ms[n - 1][1])
