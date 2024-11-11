from bisect import bisect_right
from itertools import accumulate
from sys import stdin

all_in = stdin.readlines()

n, m = map(int, all_in[0].split())
p = [tuple(map(int, el.split())) for el in all_in[1:]]

a = [el[0] for el in p]
b = [el[1] for el in p]
c = [a[i] - b[i] for i in range(n)]

s = sum(a)

if s <= m:
    print(0)
    exit()

k = s - m
c.sort(reverse=True)

acc = list(accumulate(c))
b = bisect_right(acc, k)

if b == n:
    print(-1)
    exit()

print(b + 1)
