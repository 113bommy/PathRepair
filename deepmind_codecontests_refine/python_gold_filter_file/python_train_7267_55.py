N = int(input())
A = [int(a) for a in input().split()]
I = 0
J = 0
K = 0
for a in A:
    if a == 1:
        J += 1
        K += 1
    elif a == 2:
        K += 1

X = [[[0.0] * (j+1) for j in range(k+1)] for k in range(N+1)]

for k in range(N+1)[::-1]:
    for j in range(k+1)[::-1]:
        for i in range(j+1)[::-1]:
            if i == N:
                X[k][j][i] = 0
            else:
                X[k][j][i] = N/(N-i)
                if i < j:
                    X[k][j][i] += X[k][j][i+1] * (j-i) / (N-i)
                if j < k:
                    X[k][j][i] += X[k][j+1][i] * (k-j) / (N-i)
                if k < N:
                    X[k][j][i] += X[k+1][j][i] * (N-k) / (N-i)

print(X[K][J][I])