import sys
from collections import deque
input = sys.stdin.readline

n,m = map(int,input().split())
x = list(map(int,input().split()))

q = deque(x)

used = set(x)
ans = set()
cnt = 0

while cnt < m:
    i = q.popleft()
    if i not in used:
        used.add(i)
        ans.add(i)
        cnt += 1
    if i+1 not in used:
        q.append(i+1)
    if i-1 not in used:
        q.append(i-1)

i = 0
ans = sorted(list(ans))
dist = 0

for y in ans:
    while i+1 < n and abs(x[i+1] - y) < abs(x[i] - y):
        i += 1
    dist += abs(x[i] - y)

print(dist)
print(*ans)
