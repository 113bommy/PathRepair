from sys import setrecursionlimit as SRL, stdin

SRL(10 ** 7)
rd = stdin.readline
rrd = lambda: map(int, rd().strip().split())

n = int(input())
a = list(rrd())
a = [0] + a + a + a
bit = [10 ** 10] * 200005


def add(i, x):
    while i <= 3 * n+1:
        bit[i] = min(bit[i], x)
        i += i & -i


def query(x):
    ans = 10 ** 10
    while x:
        ans = min(ans, bit[x])
        x -= x & -x
    return ans


ans = [0] * 200005
ans[3 * n + 1] = 3 * n + 1
from collections import deque

p = deque()

for i in range(3 * n, 0, -1):
    x = a[i]
    while len(p) and p[0][0] <= x:
        p.popleft()
    pos = p[0][1] if p else 3 * n + 1
    p.appendleft([x, i])
    r = pos
    if query(r) * 2 > x:
        ans[i] = ans[r]
        add(i, x)
        continue
    l = i
    while l < r:
        m = (l + r) // 2
        if query(m) * 2 < x:
            r = m
        else:
            l = m + 1
    ans[i] = r
    add(i, x)

for i in range(1, n + 1):
    if ans[i] == 3 * n + 1:
        print(-1, end=' ')
    else:
        print(ans[i] - i, end=' ')
