n, d, a = map(int, input().split())
p = []
for i in range(n):
    x, h = map(int, input().split())
    p.append((x, h))

from collections import deque

p.sort()

q = deque()
total = 0
ans = 0
for i in range(n):
    x, h = p[i][0], p[i][1]
    while q and q[0][0] <= x:
        total -= q[0][1]
        q.popleft()
    h -= total
    if h > 0:
        num = (h+a-1)//a
        ans += num
        damage = num*a
        total += damage
        q.append((x+2*d, damage))

print(ans)