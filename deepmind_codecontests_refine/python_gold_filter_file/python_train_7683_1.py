N = int(input())
A = [[int(a) for a in input().split()] for _ in range(N)]
X = [0] * (1<<N)
for s in range(1, 1<<N):
    t = s & (s-1)
    ma = sum([sum([A[i][j] for j in range(i) if 1 << j & s]) for i in range(N) if 1 << i & s])
    while t:
        ma = max(ma, X[t] + X[s^t])
        t = (t-1) & s
    X[s] = ma
print(X[-1])