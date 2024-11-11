N, M, Q = map(int, input().split())
matrix = [[0]*(N+1) for _ in range(N)]

for _ in range(M):
    l, r = map(int, input().split())
    matrix[l-1][r] += 1

for i in range(N):
    for j in range(1, N+1):
        matrix[i][j] += matrix[i][j-1]

for _ in range(Q):
    p, q = map(int, input().split())
    ans = 0
    for i in range(p-1, q):
        ans += matrix[i][q]-matrix[i][p-1]
    print(ans)