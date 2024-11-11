n, m, l = map(int, input().split())

A = [list(map(int, input().split())) for i in range(n)]
B = [list(map(int, input().split())) for j in range(m)]
C = [ [sum([A[k][j] * B[j][i] for j in range(m)]) for i in range(n)] for k in range(n)]

for i in range(n):
    C[i] = map(str, C[i])
    print(" ".join(C[i]))