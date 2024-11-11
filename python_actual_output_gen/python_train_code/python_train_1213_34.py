N, K = map(int, input().split())
V = list(map(int, input().split()))
ans = 0
for i in range(min(N, K)):
    for j in range(i + 1):
        for k in range(K - i + 1):
            ans = max(ans, sum(sorted(V[:i - j] 
                                      + list(reversed(V))[:j])[k:]))
print(ans)