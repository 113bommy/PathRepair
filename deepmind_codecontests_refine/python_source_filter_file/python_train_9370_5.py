n = int(input()))
M = [[0] * n for i in range(n)]
for i in range(n):
    u = list(map(int, input().split()))
    v = u[0]
    for j in u[2:]:
        M[u - 1][v - 1] = 1

for i in M:
    print(*i)