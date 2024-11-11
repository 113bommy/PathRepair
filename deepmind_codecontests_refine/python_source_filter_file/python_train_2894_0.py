N, Q = map(int, input().split())
ab = [list(map(int, input().split())) for i in range(N-1)]
px = [list(map(int, input().split())) for i in range(Q)]
cnt = [0] * N

for p, x in px:
    cnt[p-1] += x
for a, b in ab:
    cnt[b-1] += cnt[a-1]

print(*cnt)