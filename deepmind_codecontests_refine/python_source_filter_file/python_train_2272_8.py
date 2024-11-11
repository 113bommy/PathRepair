from itertools import permutations


N, C = map(int, input().split())
D = [list(map(int, input().split())) for _ in range(C)]
c = [list(map(int, input().split())) for _ in range(N)]
cost = [[0] * 3 for _ in range(C)]

for i in range(N):
    for j in range(N):
        for k in range(C):
            cost[k][(i + j) % 3] += D[c[i][j] - 1][k]


ans = min(
    sum(cost[c][i] for i, c in enumerate(colors))
    for colors in permutations(range(C), 3)
)
print(ans)
