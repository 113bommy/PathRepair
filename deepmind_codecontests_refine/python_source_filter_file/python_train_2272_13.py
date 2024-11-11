import itertools

N, C = map(int, input().split())
d = [list(map(int, input().split())) for _ in range(C)]
c = [list(map(int, input().split())) for _ in range(N)]

memo = [[0 for i in range(C)]for j in range(3)]

for i in range(N):
    for j in range(N):
        cij = c[i][j]
        a = (i + j + 2) % 3
        for k in range(C):
            memo[a][k] += d[cij-1][k]

ans = 25000000


for c1, c2, c3 in itertools.permutations(range(C), 3):
    ans = min(ans, memo[0][c1] + memo[1][c2] + memo[2][c3])

print(ans)