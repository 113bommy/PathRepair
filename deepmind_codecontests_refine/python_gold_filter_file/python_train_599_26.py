N, S = map(int, input().split())
A = [int(a) for a in input().split()]
X = [0] * 3001
ans = 0
P = 998244353
for i, a in enumerate(A):
    X[0] += 1
    for j in range(S, a-1, -1):
        X[j] = (X[j] + X[j-a]) % P
    ans += X[S]
print(ans % P)