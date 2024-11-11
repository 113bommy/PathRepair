from heapq import heapify, heappush, heappop
import sys
input = sys.stdin.readline

N, D, A = map(int, input().split())
monsters = [tuple(map(int, input().split())) for _ in range(N)]
heapify(monsters)

max_H = 10**9
ans = 0
damage = 0
while monsters:
    x, h = heappop(monsters)
    if h <= max_H:
        h -= damage
        if h <= 0:
            continue
        bomb = (h+A-1) // A
        damage += bomb * A
        ans += bomb
        heappush(monsters, (x+2*D, max_H+bomb*A))
    else:
        damage -= h-max_H
print(ans)
