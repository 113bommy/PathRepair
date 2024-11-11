from collections import deque
import math

N, D, A = map(int, input().split())
monster = [list(map(int, input().split())) for _ in range(N)]
monster.sort(key=lambda x:x[0])

bomb = deque()
s = 0
ans = 0
for i in range(N):
    x, h = monster[i]
    while len(bomb) > 0 and bomb[0][1] < x:
        s -= bomb.popleft()[2]
    h -= s
    if h > 0:
        cnt = math.ceil((h-s)/A)
        damage = cnt*A
        bomb.append([x, x+2*D, damage])
        s += damage
        ans += cnt
print(ans)