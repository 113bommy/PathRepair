from bisect import *
n, d, a = map(int, input().split())
monster = []

for i in range(n):
    x, h = map(int, input().split())
    monster.append([x, h])

monster.sort()
hp = []
x = []
damage = [0] * (n+1)

for i in range(n):
    hp.append(monster[i][1])
    x.append(monster[i][0])

ans = 0
for i in range(n):
    bomb = max((hp[i] - damage[i] - 1) // a + 1, 0)
    ans += bomb
    damage[i] += bomb * a
    damage[bisect_right(x, x[i]+2*d)] -= bomb * a
    damage[i+1] += damage[i]

print(ans)
