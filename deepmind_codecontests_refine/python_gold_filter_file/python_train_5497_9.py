N, K = map(int, input().split())
P = 10**9+7
R = int(N**0.5)+1
A = [i for i in range(R)] + [N//i for i in range(1, R)][::-1]
M = len(A)
X = [0] + [1] * (M-1)
for i in range(1, K+1):
    NX = [0] * M
    for j in range(1, M):
        NX[j] = (NX[j-1] + X[M-j]*(A[j]-A[j-1])) % P
    X = NX
print(X[-1])