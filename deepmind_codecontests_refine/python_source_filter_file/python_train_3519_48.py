N, K = map(int, input().split())
V = list(map(int, input().split()))
M = min(N, K)
ans = 0
for i in range(M+1):
    for a in range(i+1):
        L = sorted(V[:a] + V[N-(i-a):], reverse=True)
        for _ in range(M-i):
            if L and L[-1] < 0:
                L.pop()
            else:
                break
        ans = max(ans, sum(L))
print(ans)