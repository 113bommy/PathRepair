n,d,a=map(int,input().split())
xh=[list(map(int,input().split())) for _ in range(n)]
xh.sort()

import collections
pq=collections.deque()

ans = 0
totalDamage = 0


for i in range(n):
    x,h = xh[i]
    while len(pq) > 0 and pq[0][0] < x:
        totalDamage -= pq[0][1]
        pq.popleft()
    h -=totalDamage
    if h <= 0:
        continue
    num = (h + a -1) //a
    ans += num
    dam = num*a
    totalDamage += dam
    pq.append((x+2*d,dam))

print(ans)