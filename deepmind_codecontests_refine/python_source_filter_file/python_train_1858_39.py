import sys
stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
nn = lambda: list(stdin.readline().split())
ns = lambda: stdin.readline().rstrip()

from collections import Counter

h,w = na()
c = Counter()

for i in range(h):
    c.update(ns())

c = list(c.values())

for i in range(len(c)):
    c[i] %= 4

print(c)
v,x,y,z = c.count(0),c.count(1),c.count(2),c.count(3)

if x+z > 1:
    print('No')
else:
    a = y+z
    if h%2 == 1:
        a -= w//2
    if w%2 == 1:
        a -= h//2
    if a <= 0:
        print('Yes')
    else:
        print('No')