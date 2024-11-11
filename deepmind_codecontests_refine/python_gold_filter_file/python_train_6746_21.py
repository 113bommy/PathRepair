from bisect import bisect_left
from collections import deque
n = int(input())
A=[int(input()) for _ in range(n)]
q=deque()
for a in A:
    i=bisect_left(q,a)
    if not i:
        q.appendleft(a)
    else:
        q[i-1]=a
print(len(q))