#!/usr/bin/env python
import sys

def check(a):
    d = [a[i] - a[i - 1] for i in range(1, len(a))]
    c = d[0]
    return all(di == c for di in d)


n = int(input())
b = list(map(int, input().split()))
b = [(b[i], i + 1) for i in range(n)]
b.sort()
a, p = [b[i][0] for i in range(n)], [b[i][1] for i in range(n)]

if n <= 3:
    print(1)
    sys.exit(0)

if check(a):
    print(1)
    sys.exit(0)

if check(a[1:]):
    print(p[0])
    sys.exit(0)

aa = [a[0]]; aa.extend(a[2:])
if check(aa):
    print(p[1])
    sys.exit(0)

d = [a[i] - a[i - 1] for i in range(1, len(a))]
idx = 0
while d[idx] == d[0]:
    idx += 1
aa = a[:idx + 1]; aa.extend(a[idx + 2:])
# print(f'aa = {aa}')
if check(aa):
    print(p[idx + 1])
else:
    print(-1)
