import sys
import collections
from math import floor, ceil, log2
#sys.stdin = open('input.txt', 'r')
inp = lambda: sys.stdin.readline().strip()

n, m = map(int, inp().split())
a = [[0] * m for i in range(n)]
b = [[0] * m for i in range(n)]
for i in range(n):
    s = list(map(int, inp().split()))
    for j in range(m):
        a[i][j] = s[j]
for i in range(n):
    s = list(map(int, inp().split()))
    for j in range(m):
        b[i][j] = s[j]
x, y = 0, 0
for k in range(n - 1 + m - 1):
    i, j = x, y
    t1, t2 = [], []
    while i + j == k:
        if i < 0 or j >= m:
            break
        t1.append(a[i][j])
        t2.append(b[i][j])
        i -= 1
        j += 1
    t1.sort()
    t2.sort()
    ok = False
    for i in range(len(t1)):
        if t1[i] != t2[i]:
            ok = True
            print('NO')
            sys.exit(0)
    if x < n - 1:
        x += 1
    else:
        y += 1
print('YES')