from collections import deque
n, d, a = map(int, input().split())
p = [list(map(int, input().split())) for _ in range(n)]
p.sort()
d *= 2
ans, tot = 0, 0
q = deque()
for x, h in p:
    while (q and q[0][0] < x):
        tot -= q[0][1]
        q.popleft()
    h -= tot
    if h>0:
        num = (h+a-1)//a
        ans += num
        damage = num*a
        tot += damage
        q.append((x+d, damage))
print(ans)
