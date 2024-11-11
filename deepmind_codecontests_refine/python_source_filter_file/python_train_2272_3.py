from itertools import permutations

N, C = map(int, input().split())
D = [[int(x) for x in input().split()] for _ in range(C)]
c = [[int(x) for x in input().split()] for _ in range(N)]

n_color = [[0 for _ in range(3)] for _ in range(C)]
for i in range(N):
    for j in range(N):
        X = c[i][j] - 1
        n_color[(i + j + 2) % 3][X] += 1

ans = float('inf')
for paint in permutations(range(C), 3):
    cost = 0
    for ij3 in range(3):
        Y = paint[ij3]
        for X in range(C):
            cost += D[X][Y] * n_color[ij3][X]
    ans = min(ans, cost)
print(ans)