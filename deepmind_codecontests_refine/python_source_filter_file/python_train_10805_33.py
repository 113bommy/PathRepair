import sys
from collections import deque

n = int(input())
matches = [[a - 1 for a in map(int, line.split())] for line in sys.stdin]
#print(matches)
q = deque(range(n))
#print(q)
depth = [0] * n
waiting = [-1] * n

while q:
    a = q.popleft()
    b = matches[a].pop()
    print(a, b)
    if waiting[b] == a:
        depth[a] = depth[b] = max(depth[a], depth[b]) + 1
        if matches[a]:
            q.append(a)
        if matches[b]:
            q.append(b)
    else:
        waiting[a] = b

if any(matches):
    print(-1)
else:
    print(max(depth))