# coding: utf-8
import sys

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

N, Q = lr()
STX = [tuple(lr()) for _ in range(N)]
event = []
for s, t, x in STX:
    event.append((s-x, 0, x))
    event.append((t-x, -1, x))

for i in range(Q):
    d = ir()
    event.append((d, 1, i))

event.sort()
answer = [-1] * Q
cur = set()
flag = False
INF = 10 ** 10
min_x = INF
for a, b, c in event:
    if b == 0:
        cur.add(c)
        if c < min_x:
            min_x = c
            flag = True
    elif b == -1:
        cur.remove(c)
        if min_x == c:
            flag = False
    elif b == 1:
        if cur:
            if not flag:
                min_x = min(cur)
                flag = True
            answer[c] = min_x

print('\n'.join(map(str, answer)))
# 19