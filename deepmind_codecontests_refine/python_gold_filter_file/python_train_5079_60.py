from math import ceil
from collections import deque

n, d, a = map(int, input().split())
m = sorted([list(map(int, input().split())) for _ in range(n)])
m = [[x, ceil(h / a)] for x, h in m]

acc_damage = 0
que = deque()
ans = 0
for x, h in m:
    while que and x > que[0][0]:
        limit, damage = que.popleft()
        acc_damage -= damage

    need = max(0, h - acc_damage)
    ans += need
    acc_damage += need

    if need:
        que.append([x + 2 * d, need])

print(ans)
