from collections import deque
from bisect import bisect_left
N=int(input())
d=deque()
for i in range(N):
    A=int(input())
    b=bisect_left(d,A)-1
    if b==-1:
        d.appendleft(A)
    else:
        d[b]=A
print(len(d))