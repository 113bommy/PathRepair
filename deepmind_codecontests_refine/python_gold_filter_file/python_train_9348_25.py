N, K  = map(int, input().split())
M = 10 ** 9 + 7

C = [[0 for j in range(N+3)] for i in range(N+3)]
C[1][1] = 1

for i in range(2, N+2):
    for j in range(1, i+2):
        C[i][j] = C[i-1][j] + C[i-1][j-1]

for i in range(1, K+1):
    print(C[N-K+2][i+1] * C[K][i] %  M)
