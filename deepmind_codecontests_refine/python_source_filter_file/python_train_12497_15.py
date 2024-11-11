n, m, l = map(int, input().split())

A = []
B = []

for _ in range(n):
    A.append(list(map(int, input().split())))

for _ in range(m):
    B.append(list(map(int, input().split())))

C = [[sum([A[i][k] * B[k][j] for k in range(m)]) for j in range(n)] for i in range(l)]

for row in C:
    print(' '.join(map(str, row)))