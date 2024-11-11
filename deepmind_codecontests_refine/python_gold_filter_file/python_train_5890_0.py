#!/usr/bin/env python3
from collections import deque


n = int(input())
p = list(input())

rq = deque()
dq = deque()

for i, e in enumerate(p):
    if e == 'D':
        dq.append(i)
    else:
        rq.append(i)

while rq and dq:
    d = dq.popleft()
    r = rq.popleft()
    if d > r:
        rq.append(r+n)
    else:
        dq.append(d+n)
if rq:
    print('R')
else:
    print('D')




