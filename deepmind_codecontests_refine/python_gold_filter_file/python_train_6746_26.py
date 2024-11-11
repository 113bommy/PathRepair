import bisect
from collections import deque
n = int(input())
l = deque([])
l.append(int(input()))
for i in range(n-1):
    a = int(input())
    if l[0] >= a:
        l.appendleft(a)
    else:
        l[bisect.bisect_left(l,a)-1] = a
print(len(l))
