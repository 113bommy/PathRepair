#!/usr/bin/env python3
n, m = map(int, input().split())
mm = 10**5 + 1
for i in range(m):
    l, r = map(int, input().split())
    mm = min(mm, r-l)
print(mm+1)
for i in range(n):
    if i != n-1:
        print(i % (mm+1), end=" ")
    else:
        print(i % mm)

