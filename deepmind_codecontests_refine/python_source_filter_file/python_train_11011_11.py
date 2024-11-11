N, K = map(int, input().split())
A = list(map(int, input().split()))

A = A + [0]
K = min(K, 100)
for k in range(K):
    t = [0]*(N+1)
    for i in range(N):
        l = max(i-A[i], 0)
        r = min(i+A[i], N-1)
        t[l] += 1
        t[r+1] -= 1

    S = [0]*N
    S[0] = t[0]
    for i in range(1, N):
        S[i] = S[i-1] + t[i]

    A = S.copy()
print(*S)